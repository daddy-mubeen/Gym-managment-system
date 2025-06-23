@ Usage

Upon starting the application, you will see the main menu with options to manage members, trainers, equipment, and membership plans. Follow the prompts to add, display, or search for members and trainers. Access the sorting and searching algorithms demo to see how different algorithms perform with the data.

@ Code Structure

MembershipPlan: Class representing a membership plan with attributes like ID, name, duration, price, and benefits. Member: Class representing a gym member with attributes like ID, name, email, phone, membership plan ID, shift, join date, and status. Trainer: Class representing a trainer with attributes like ID, name, specialization, phone, salary, shift, join date, and availability. Equipment: Class representing gym equipment with attributes like ID, name, category, purchase date, cost, and status. GymManagementSystem: Main class that manages all functionalities, including member and trainer management, sorting, searching, and reporting.

@ Algorithms

Sorting:

Quick Sort for sorting members by name or ID. Merge Sort for sorting trainers by salary.
Searching:

Linear Search for finding members by name or email. Binary Search for finding members by ID (requires sorted data). Depth-First Search (DFS) for searching equipment by category. Breadth-First Search (BFS) for searching trainers by specialization.

@ Performance

The system demonstrates the time complexity of various algorithms: Quick Sort: O(n log n) average, O(n²) worst case. Merge Sort: O(n log n) guaranteed. Linear Search: O(n). Binary Search: O(log n). DFS/BFS: O(V + E).
@ Contributing Contributions are welcome! If you have suggestions for improvements or new features, feel free to submit a pull request or open an issue.

@ Acknowledgments Thanks to the open-source community for providing resources and libraries that made this project possible. Special thanks to contributors who have helped improve the system.