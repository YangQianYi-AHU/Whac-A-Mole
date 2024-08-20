# Whac-A-Mole
Whac-A-Mole is a game where you hit popping moles quickly to score points.
1. Project Overview
1.1 Project Title
Whac-A-Mole Game

1.2 Project Description
The Whac-A-Mole game is a classic arcade game where the player’s goal is to hit as many moles as possible within a given time frame. The game is developed using C++ and utilizes the SFML (Simple and Fast Multimedia Library) for rendering graphics, handling input, and managing sound effects. The moles will randomly pop up from predefined positions on the screen, and the player must quickly react by hitting them with a hammer to score points.

1.3 Objectives
Develop a simple interactive game using C++.
Implement basic game mechanics such as random mole appearance, user input handling, and scoring.
Utilize a graphics library (SFML) to manage game visuals and sound effects.
Provide a fun and engaging user experience.
2. System Requirements
2.1 Hardware Requirements
Processor: Intel Core i3 or equivalent
RAM: 4GB or higher
Storage: 100MB free disk space
Display: 1280x720 resolution or higher
2.2 Software Requirements
Operating System: Windows 10 or later, macOS, Linux
Development Environment: Visual Studio, Code::Blocks, or CLion
C++ Compiler: GCC, MinGW, or MSVC
Libraries: SFML 2.5 or later
3. Game Design
3.1 Game Mechanics
Moles: Moles appear randomly in different positions on the screen. Each mole stays visible for a limited time before disappearing if not hit.
Hammer: The hammer follows the mouse cursor, and when the player clicks, the hammer attempts to hit a mole.
Scoring: The player earns points for every mole successfully hit. The score is displayed in the game interface.
Timer: The game runs for a set duration, typically 60 seconds. After the time runs out, the game ends and the final score is displayed.
3.2 User Interface
Main Menu: Start Game, Instructions, Exit
Game Screen: Displays the game area, current score, and remaining time.
End Screen: Shows the player’s final score and provides an option to restart the game or exit.
3.3 Graphics and Sound
Graphics: Simple 2D graphics for moles, hammer, and background. Images or shapes can be used for each game element.
Sound: Sound effects for hitting moles, game start, and game over.
4. Development Plan
4.1 Project Setup
Set up the C++ development environment.
Install and configure the SFML library.
4.2 Implementation
Stage 1: Basic Game Structure

Set up the game window and basic game loop.
Implement the Mole class with random appearance logic.
Implement the Hammer class to follow the mouse and detect hits.
Stage 2: Scoring and Timer

Add score tracking and display on the screen.
Implement a countdown timer for the game duration.
Stage 3: User Interface

Create the main menu and end screen.
Add instructions and an option to restart the game.
Stage 4: Sound Effects and Final Touches

Integrate sound effects for hitting moles and game events.
Optimize game performance and fix any bugs.
4.3 Testing
Test each component of the game individually.
Perform integration testing to ensure all parts work together smoothly.
Conduct user testing to gather feedback and make improvements.
4.4 Documentation
Document the code with comments and explanations.
Create a user manual with instructions on how to play the game.
Prepare the final project report.
5. Deliverables
5.1 Source Code
Complete C++ source code files (.cpp, .h) with proper structure and documentation.
5.2 Executable
Compiled executable file (.exe) for Windows (or equivalent for other platforms).
5.3 User Manual
A document detailing how to install, run, and play the game.
5.4 Project Report
This documentation, including the design process, implementation details, and testing results.
6. Conclusion
The Whac-A-Mole game project provides an excellent opportunity to apply C++ programming skills in a fun and interactive way. Through this project, fundamental concepts of game development, such as user input handling, real-time graphics, and game logic implementation, are explored and utilized.
