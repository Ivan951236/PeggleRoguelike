package ua.ivan95.pegglepegs

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.material3.* // Keep this
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.navigation.NavController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.currentBackStackEntryAsState
import androidx.navigation.compose.rememberNavController
import ua.ivan95.pegglepegs.ui.theme.PeggleRoguelikePresetGeneratorTheme
import kotlin.random.Random

// Sealed class to define your navigation routes
sealed class Screen(val route: String, val title: String) {
    object PeggleLevels : Screen("peggle_levels", "Peggle Levels")
    object BossLevel : Screen("boss_level", "Boss Level")
    object Inventory : Screen("inventory", "Inventory")
}

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            PeggleRoguelikePresetGeneratorTheme {
                AppNavigator()
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class) // <--- ADD THIS ANNOTATION HERE
@Composable
fun AppNavigator() {
    val navController = rememberNavController()
    Scaffold( // Scaffold is a Material 3 component
        topBar = {
            TopAppBar(title = { // TopAppBar is also a Material 3 component
                val currentRoute =
                    navController.currentBackStackEntryAsState().value?.destination?.route
                val title = when (currentRoute) {
                    Screen.PeggleLevels.route -> Screen.PeggleLevels.title
                    Screen.BossLevel.route -> Screen.BossLevel.title
                    Screen.Inventory.route -> Screen.Inventory.title
                    else -> "Peggle App"
                }
                Text(text = title)
            })
        },
        bottomBar = {
            BottomNavigationBar(navController = navController) // NavigationBar and NavigationBarItem are also Material 3
        }
    ) { innerPadding ->
        NavHost(
            navController = navController,
            startDestination = Screen.PeggleLevels.route,
            modifier = Modifier.padding(innerPadding)
        ) {
            composable(Screen.PeggleLevels.route) { PeggleLevelsScreen() }
            composable(Screen.BossLevel.route) { BossLevelScreen() }
            composable(Screen.Inventory.route) { InventoryScreen() }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class) // <--- YOU MIGHT NEED IT HERE TOO if BottomNavigationBar uses experimental APIs directly
@Composable
fun BottomNavigationBar(navController: NavController) {
    val items = listOf(
        Screen.PeggleLevels,
        Screen.BossLevel,
        Screen.Inventory
    )
    NavigationBar { // NavigationBar is Material 3
        val currentRoute = navController.currentBackStackEntryAsState().value?.destination?.route
        items.forEach { screen ->
            NavigationBarItem( // NavigationBarItem is Material 3
                icon = { /* You can add icons here */ },
                label = { Text(screen.title) },
                selected = currentRoute == screen.route,
                onClick = {
                    navController.navigate(screen.route) {
                        popUpTo(navController.graph.startDestinationId) {
                            saveState = true
                        }
                        launchSingleTop = true
                        restoreState = true
                    }
                }
            )
        }
    }
}


@Composable
fun PeggleLevelsScreen() {
    val peggleLevelsData = remember { generatePeggleLevels() } // Generate data once

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("Peggle Levels", style = MaterialTheme.typography.headlineMedium)
        Spacer(modifier = Modifier.height(16.dp))
        peggleLevelsData.forEach { (mainNum, secondNum) ->
            Text("Level: $mainNum, Modifier: $secondNum")
        }
    }
}

@Composable
fun BossLevelScreen() {
    val bossLevelData = remember { generateBossLevel() } // Generate data once

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("Boss Level", style = MaterialTheme.typography.headlineMedium)
        Spacer(modifier = Modifier.height(16.dp))
        Text("Boss: ${bossLevelData.first}, Modifier: ${bossLevelData.second}")
    }
}

@Composable
fun InventoryScreen() {
    val inventoryData = remember { generateInventory() } // Generate data once

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("Inventory", style = MaterialTheme.typography.headlineMedium)
        Spacer(modifier = Modifier.height(16.dp))
        inventoryData.forEach { item ->
            Text("Item Power: $item")
        }
    }
}

// Function to generate numbers for "Peggle Levels"
fun generatePeggleLevels(): List<Pair<Int, Int>> {
    val levels = mutableListOf<Pair<Int, Int>>()
    repeat(15) {
        val mainNumber = Random.nextInt(1, 46) // Generates a number between 1 and 45 (inclusive)
        val secondNumber = Random.nextInt(1, 11) // Generates a number between 1 and 10 (inclusive)
        levels.add(Pair(mainNumber, secondNumber))
    }
    return levels
}

// Function to generate numbers for "Boss Level"
fun generateBossLevel(): Pair<Int, Int> {
    val mainNumber = Random.nextInt(50, 56) // Generates a number between 50 and 55 (inclusive)
    val secondNumber = Random.nextInt(1, 11)  // Generates a number between 1 and 10 (inclusive)
    return Pair(mainNumber, secondNumber)
}

// Function to generate numbers for "Inventory"
fun generateInventory(): List<Int> {
    val items = mutableListOf<Int>()
    repeat(3) {
        items.add(Random.nextInt(1, 11)) // Generates a number between 1 and 10 (inclusive)
    }
    return items
}
