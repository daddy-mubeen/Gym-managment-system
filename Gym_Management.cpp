#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <chrono>
#include <queue>

using namespace std;

class MembershipPlan {
private:
    int planId;
    string planName;
    int duration;
    double price;
    string benefits;

public:
    MembershipPlan(int id, string name, int dur, double p, string ben)
        : planId(id), planName(name), duration(dur), price(p), benefits(ben) {}

    int getId() const { return planId; }
    string getName() const { return planName; }
    int getDuration() const { return duration; }
    double getPrice() const { return price; }
    string getBenefits() const { return benefits; }

    void displayPlan() const {
        cout << "Plan ID: " << planId << " | Name: " << planName 
             << " | Duration: " << duration << " months | Price: $" << price 
             << " | Benefits: " << benefits << endl;
    }
};

class Member {
private:
    int memberId;
    string name;
    string email;
    string phone;
    int membershipPlanId;
    string shift;
    string joinDate;
    bool isActive;

public:
    Member(int id, string n, string e, string p, int planId, string s, string date) 
        : memberId(id), name(n), email(e), phone(p), membershipPlanId(planId), 
          shift(s), joinDate(date), isActive(true) {}

    int getId() const { return memberId; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    int getMembershipPlanId() const { return membershipPlanId; }
    string getShift() const { return shift; }
    string getJoinDate() const { return joinDate; }
    bool getStatus() const { return isActive; }
    
    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }
    void setPhone(string p) { phone = p; }
    void setMembershipPlan(int planId) { membershipPlanId = planId; }
    void setShift(string s) { shift = s; }
    void deactivate() { isActive = false; }
    void activate() { isActive = true; }

    void displayMember() const {
        cout << "ID: " << memberId << " | Name: " << name << " | Email: " << email 
             << " | Phone: " << phone << " | Plan ID: " << membershipPlanId 
             << " | Shift: " << shift << " | Joined: " << joinDate 
             << " | Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};

class Trainer {
private:
    int trainerId;
    string name;
    string specialization;
    string phone;
    double salary;
    string shift;
    string joinDate;
    bool isAvailable;

public:
    Trainer(int id, string n, string spec, string p, double sal, string s, string date)
        : trainerId(id), name(n), specialization(spec), phone(p), 
          salary(sal), shift(s), joinDate(date), isAvailable(true) {}

    int getId() const { return trainerId; }
    string getName() const { return name; }
    string getSpecialization() const { return specialization; }
    string getPhone() const { return phone; }
    double getSalary() const { return salary; }
    string getShift() const { return shift; }
    string getJoinDate() const { return joinDate; }
    bool getAvailability() const { return isAvailable; }

    void setName(string n) { name = n; }
    void setSpecialization(string spec) { specialization = spec; }
    void setPhone(string p) { phone = p; }
    void setSalary(double sal) { salary = sal; }
    void setShift(string s) { shift = s; }
    void setUnavailable() { isAvailable = false; }
    void setAvailable() { isAvailable = true; }

    void displayTrainer() const {
        cout << "ID: " << trainerId << " | Name: " << name << " | Specialization: " 
             << specialization << " | Phone: " << phone << " | Salary: $" << salary 
             << " | Shift: " << shift << " | Joined: " << joinDate << " | Status: " 
             << (isAvailable ? "Available" : "Unavailable") << endl;
    }
};

class Equipment {
private:
    int equipmentId;
    string name;
    string category;
    string purchaseDate;
    double cost;
    bool isWorking;

public:
    Equipment(int id, string n, string cat, string date, double c)
        : equipmentId(id), name(n), category(cat), purchaseDate(date), 
          cost(c), isWorking(true) {}

    int getId() const { return equipmentId; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    string getPurchaseDate() const { return purchaseDate; }
    double getCost() const { return cost; }
    bool getStatus() const { return isWorking; }

    void setName(string n) { name = n; }
    void setCategory(string cat) { category = cat; }
    void markBroken() { isWorking = false; }
    void markWorking() { isWorking = true; }

    void displayEquipment() const {
        cout << "ID: " << equipmentId << " | Name: " << name << " | Category: " 
             << category << " | Purchase Date: " << purchaseDate << " | Cost: $" 
             << cost << " | Status: " << (isWorking ? "Working" : "Broken") << endl;
    }
};

class GymManagementSystem {
private:
    vector<Member> members;
    vector<Trainer> trainers;
    vector<Equipment> equipments;
    vector<MembershipPlan> membershipPlans;
    unordered_map<int, int> memberIndex;
    unordered_map<string, int> memberEmailIndex;
    unordered_map<int, int> trainerIndex;
    unordered_map<string, vector<int>> shiftMembers;
    unordered_map<string, vector<int>> shiftTrainers;
    int nextMemberId;
    int nextTrainerId;
    int nextEquipmentId;
    int nextPlanId;

    // SORTING ALGORITHM 1: QUICK SORT
    void quickSort(vector<Member>& arr, int low, int high, string sortBy) {
        if (low < high) {
            int pi = partition(arr, low, high, sortBy);
            quickSort(arr, low, pi - 1, sortBy);
            quickSort(arr, pi + 1, high, sortBy);
        }
    }

    int partition(vector<Member>& arr, int low, int high, string sortBy) {
        string pivot;
        if (sortBy == "name") {
            pivot = arr[high].getName();
        } else if (sortBy == "id") {
            pivot = to_string(arr[high].getId());
        }

        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            string current;
            if (sortBy == "name") {
                current = arr[j].getName();
            } else if (sortBy == "id") {
                current = to_string(arr[j].getId());
            }

            if (current <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    // SORTING ALGORITHM 2: MERGE SORT (for trainers by salary)
    void mergeSort(vector<Trainer>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void merge(vector<Trainer>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<Trainer> leftArr, rightArr;
        for (int i = 0; i < n1; i++)
            leftArr.push_back(arr[left + i]);
        for (int j = 0; j < n2; j++)
            rightArr.push_back(arr[mid + 1 + j]);

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i].getSalary() <= rightArr[j].getSalary()) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    // SEARCHING ALGORITHM 1: LINEAR SEARCH
    int linearSearch(const vector<Member>& arr, string searchTerm, string searchBy) {
        cout << "\n[LINEAR SEARCH] Starting search..." << endl;
        auto start = chrono::high_resolution_clock::now();
        
        for (int i = 0; i < arr.size(); i++) {
            if (searchBy == "name" && arr[i].getName() == searchTerm) {
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "[LINEAR SEARCH] Found in " << duration.count() << " microseconds" << endl;
                cout << "[LINEAR SEARCH] Time Complexity: O(n)" << endl;
                return i;
            } else if (searchBy == "email" && arr[i].getEmail() == searchTerm) {
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "[LINEAR SEARCH] Found in " << duration.count() << " microseconds" << endl;
                cout << "[LINEAR SEARCH] Time Complexity: O(n)" << endl;
                return i;
            }
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "[LINEAR SEARCH] Search completed in " << duration.count() << " microseconds" << endl;
        cout << "[LINEAR SEARCH] Time Complexity: O(n)" << endl;
        return -1;
    }

    // SEARCHING ALGORITHM 2: BINARY SEARCH (on sorted member IDs)
    int binarySearch(const vector<Member>& arr, int targetId) {
        cout << "\n[BINARY SEARCH] Starting search..." << endl;
        cout << "[BINARY SEARCH] Prerequisite: Array must be sorted by ID" << endl;
        auto start = chrono::high_resolution_clock::now();
        
        int left = 0, right = arr.size() - 1;
        int iterations = 0;
        
        while (left <= right) {
            iterations++;
            int mid = left + (right - left) / 2;
            cout << "[BINARY SEARCH] Iteration " << iterations << ": Checking position " 
                 << mid << " (ID: " << arr[mid].getId() << ")" << endl;
            
            if (arr[mid].getId() == targetId) {
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << "[BINARY SEARCH] Found in " << iterations << " iterations and " 
                     << duration.count() << " microseconds" << endl;
                cout << "[BINARY SEARCH] Time Complexity: O(log n)" << endl;
                return mid;
            }
            
            if (arr[mid].getId() < targetId)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "[BINARY SEARCH] Search completed in " << iterations << " iterations and " 
             << duration.count() << " microseconds" << endl;
        cout << "[BINARY SEARCH] Time Complexity: O(log n)" << endl;
        return -1;
    }

    // SEARCHING ALGORITHM 3: DEPTH-FIRST SEARCH (for equipment hierarchy/categories)
    void dfsEquipmentSearch(string targetCategory, vector<bool>& visited, 
                           vector<vector<int>>& adjList, int node, vector<int>& result) {
        visited[node] = true;
        cout << "[DFS] Visiting equipment ID: " << equipments[node].getId() 
             << " (" << equipments[node].getCategory() << ")" << endl;
        
        if (equipments[node].getCategory() == targetCategory) {
            result.push_back(node);
        }
        
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsEquipmentSearch(targetCategory, visited, adjList, neighbor, result);
            }
        }
    }

    // SEARCHING ALGORITHM 4: BREADTH-FIRST SEARCH (for trainer specialization network)
    vector<int> bfsTrainerSearch(string targetSpecialization) {
        cout << "\n[BFS] Starting breadth-first search for specialization: " 
             << targetSpecialization << endl;
        
        vector<int> result;
        vector<bool> visited(trainers.size(), false);
        queue<int> q;
        
        if (!trainers.empty()) {
            q.push(0);
            visited[0] = true;
        }
        
        int level = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            cout << "[BFS] Level " << level << ":" << endl;
            
            for (int i = 0; i < levelSize; i++) {
                int current = q.front();
                q.pop();
                
                cout << "[BFS] Checking trainer: " << trainers[current].getName() 
                     << " (Specialization: " << trainers[current].getSpecialization() << ")" << endl;
                
                if (trainers[current].getSpecialization() == targetSpecialization) {
                    result.push_back(current);
                }
                
                // Add adjacent trainers (next trainers in vector for demonstration)
                for (int j = current + 1; j < min(current + 3, (int)trainers.size()); j++) {
                    if (!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
            level++;
            if (level > 3) break; // Limit search depth for demonstration
        }
        
        cout << "[BFS] Search completed. Found " << result.size() 
             << " trainers with specialization: " << targetSpecialization << endl;
        cout << "[BFS] Time Complexity: O(V + E)" << endl;
        return result;
    }

public:
    GymManagementSystem() : nextMemberId(1001), nextTrainerId(2001), 
                           nextEquipmentId(3001), nextPlanId(101) {
        initializePlans();
        initializeSampleData(); // Add sample data for algorithm demonstration
    }

    void initializePlans() {
        membershipPlans.push_back(MembershipPlan(101, "Basic", 1, 29.99, "Gym Access"));
        membershipPlans.push_back(MembershipPlan(102, "Standard", 3, 79.99, "Gym Access + Group Classes"));
        membershipPlans.push_back(MembershipPlan(103, "Premium", 6, 149.99, "All Access + Personal Training"));
        membershipPlans.push_back(MembershipPlan(104, "VIP", 12, 299.99, "All Access + Personal Training + Nutrition"));
        nextPlanId = 105;
    }

    void initializeSampleData() {
        // Add sample members for algorithm demonstration
        members.push_back(Member(1005, "IMRAN KHAN", "nayapakistan@gym.com", "555-0101", 101, "Morning", "01/01/2024"));
        members.push_back(Member(1002, "NAWAZ SHAREEF", "mujhykyunnikala@gym.com", "555-0102", 102, "Evening", "15/01/2024"));
        members.push_back(Member(1008, "ASIM MUNIR", "fieldmarshal@gym.com", "555-0103", 103, "Morning", "20/01/2024"));
        members.push_back(Member(1001, "ZARDARI", "hehehehe@gym.com", "555-0104", 104, "Full Day", "25/01/2024"));
        members.push_back(Member(1010, "BILAWAL", "billokrtimeow@gym.com", "555-0105", 101, "Evening", "30/01/2024"));
        
        // Add sample trainers
        trainers.push_back(Trainer(2001, "ALI  Trainer", "Cardio", "555-1001", 3000, "Morning", "01/12/2023"));
        trainers.push_back(Trainer(2002, "Sarah Fitness", "Strength", "555-1002", 3500, "Evening", "15/12/2023"));
        trainers.push_back(Trainer(2003, "HASSAN Muscle", "Bodybuilding", "555-1003", 4000, "Full Day", "20/12/2023"));
        trainers.push_back(Trainer(2004, "ABDUL BARI Yoga", "Yoga", "555-1004", 2800, "Morning", "25/12/2023"));
        trainers.push_back(Trainer(2005, "SAIF CrossFit", "CrossFit", "555-1005", 3800, "Evening", "30/12/2023"));
        
        // Add sample equipment
        equipments.push_back(Equipment(3001, "Treadmill Pro", "Cardio", "01/01/2024", 2500));
        equipments.push_back(Equipment(3002, "Bench Press", "Strength", "15/01/2024", 800));
        equipments.push_back(Equipment(3003, "Dumbbells Set", "Strength", "20/01/2024", 1200));
        equipments.push_back(Equipment(3004, "Elliptical Machine", "Cardio", "25/01/2024", 1800));
        equipments.push_back(Equipment(3005, "Leg Press", "Strength", "30/01/2024", 1500));
        
        nextMemberId = 1011;
        nextTrainerId = 2006;
        nextEquipmentId = 3006;
        updateHashMaps();
    }

    void updateHashMaps() {
        memberIndex.clear();
        memberEmailIndex.clear();
        trainerIndex.clear();
        shiftMembers.clear();
        shiftTrainers.clear();
        
        for (int i = 0; i < members.size(); i++) {
            memberIndex[members[i].getId()] = i;
            memberEmailIndex[members[i].getEmail()] = i;
            shiftMembers[members[i].getShift()].push_back(i);
        }
        
        for (int i = 0; i < trainers.size(); i++) {
            trainerIndex[trainers[i].getId()] = i;
            shiftTrainers[trainers[i].getShift()].push_back(i);
        }
    }

    // NEW: SORT MEMBERS USING QUICK SORT
    void sortMembers() {
        if (members.empty()) {
            cout << "No members to sort!" << endl;
            return;
        }
        
        cout << "\n=== SORT MEMBERS USING QUICK SORT ===" << endl;
        cout << "Sort by:" << endl;
        cout << "1. Name (Alphabetical)" << endl;
        cout << "2. ID (Numerical)" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        
        vector<Member> membersCopy = members;
        
        cout << "\n[QUICK SORT] Starting sort..." << endl;
        auto start = chrono::high_resolution_clock::now();
        
        if (choice == 1) {
            quickSort(membersCopy, 0, membersCopy.size() - 1, "name");
            cout << "[QUICK SORT] Sorted by name" << endl;
        } else {
            quickSort(membersCopy, 0, membersCopy.size() - 1, "id");
            cout << "[QUICK SORT] Sorted by ID" << endl;
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "[QUICK SORT] Completed in " << duration.count() << " microseconds" << endl;
        cout << "[QUICK SORT] Time Complexity: O(n log n) average, O(n²) worst case" << endl;
        cout << "[QUICK SORT] Space Complexity: O(log n)" << endl;
        
        cout << "\n=== SORTED MEMBERS ===" << endl;
        for (const auto& member : membersCopy) {
            member.displayMember();
        }
    }

    // NEW: SORT TRAINERS USING MERGE SORT
    void sortTrainers() {
        if (trainers.empty()) {
            cout << "No trainers to sort!" << endl;
            return;
        }
        
        cout << "\n=== SORT TRAINERS BY SALARY USING MERGE SORT ===" << endl;
        vector<Trainer> trainersCopy = trainers;
        
        cout << "\n[MERGE SORT] Starting sort..." << endl;
        auto start = chrono::high_resolution_clock::now();
        
        mergeSort(trainersCopy, 0, trainersCopy.size() - 1);
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "[MERGE SORT] Completed in " << duration.count() << " microseconds" << endl;
        cout << "[MERGE SORT] Time Complexity: O(n log n) - guaranteed" << endl;
        cout << "[MERGE SORT] Space Complexity: O(n)" << endl;
        
        cout << "\n=== TRAINERS SORTED BY SALARY ===" << endl;
        for (const auto& trainer : trainersCopy) {
            trainer.displayTrainer();
        }
    }

    // NEW: ADVANCED SEARCH USING LINEAR SEARCH
    void advancedLinearSearch() {
        if (members.empty()) {
            cout << "No members to search!" << endl;
            return;
        }
        
        cout << "\n=== ADVANCED LINEAR SEARCH ===" << endl;
        cout << "Search by:" << endl;
        cout << "1. Name" << endl;
        cout << "2. Email" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        
        string searchTerm;
        cout << "Enter search term: ";
        cin.ignore();
        getline(cin, searchTerm);
        
        int result;
        if (choice == 1) {
            result = linearSearch(members, searchTerm, "name");
        } else {
            result = linearSearch(members, searchTerm, "email");
        }
        
        if (result != -1) {
            cout << "\n=== MEMBER FOUND ===" << endl;
            members[result].displayMember();
        } else {
            cout << "\nMember not found!" << endl;
        }
    }

    // NEW: BINARY SEARCH ON SORTED MEMBERS
    void binarySearchMembers() {
        if (members.empty()) {
            cout << "No members to search!" << endl;
            return;
        }
        
        cout << "\n=== BINARY SEARCH ON MEMBER IDs ===" << endl;
        
        // First sort members by ID for binary search
        vector<Member> sortedMembers = members;
        quickSort(sortedMembers, 0, sortedMembers.size() - 1, "id");
        
        cout << "Members sorted by ID for binary search:" << endl;
        for (const auto& member : sortedMembers) {
            cout << "ID: " << member.getId() << " - " << member.getName() << endl;
        }
        
        int targetId;
        cout << "\nEnter member ID to search: ";
        cin >> targetId;
        
        int result = binarySearch(sortedMembers, targetId);
        
        if (result != -1) {
            cout << "\n=== MEMBER FOUND ===" << endl;
            sortedMembers[result].displayMember();
        } else {
            cout << "\nMember not found!" << endl;
        }
    }

    // NEW: DFS SEARCH FOR EQUIPMENT BY CATEGORY
    void dfsEquipmentCategorySearch() {
        if (equipments.empty()) {
            cout << "No equipment to search!" << endl;
            return;
        }
        
        cout << "\n=== DEPTH-FIRST SEARCH (DFS) - EQUIPMENT BY CATEGORY ===" << endl;
        cout << "Available categories: Cardio, Strength" << endl;
        cout << "Enter category to search: ";
        string category;
        cin.ignore();
        getline(cin, category);
        
        // Create adjacency list for equipment (simulated hierarchy)
        vector<vector<int>> adjList(equipments.size());
        for (int i = 0; i < equipments.size() - 1; i++) {
            adjList[i].push_back(i + 1); // Simple linear connection for demonstration
        }
        
        vector<bool> visited(equipments.size(), false);
        vector<int> result;
        
        cout << "\n[DFS] Starting depth-first search..." << endl;
        auto start = chrono::high_resolution_clock::now();
        
        if (!equipments.empty()) {
            dfsEquipmentSearch(category, visited, adjList, 0, result);
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "[DFS] Search completed in " << duration.count() << " microseconds" << endl;
        cout << "[DFS] Time Complexity: O(V + E)" << endl;
        cout << "[DFS] Space Complexity: O(V)" << endl;
        
        if (!result.empty()) {
            cout << "\n=== EQUIPMENT FOUND IN CATEGORY: " << category << " ===" << endl;
            for (int index : result) {
                equipments[index].displayEquipment();
            }
        } else {
            cout << "\nNo equipment found in category: " << category << endl;
        }
    }

    // NEW: BFS SEARCH FOR TRAINERS BY SPECIALIZATION
    void bfsTrainerSpecializationSearch() {
        if (trainers.empty()) {
            cout << "No trainers to search!" << endl;
            return;
        }
        
        cout << "\n=== BREADTH-FIRST SEARCH (BFS) - TRAINERS BY SPECIALIZATION ===" << endl;
        cout << "Available specializations: Cardio, Strength, Bodybuilding, Yoga, CrossFit" << endl;
        cout << "Enter specialization to search: ";
        string specialization;
        cin.ignore();
        getline(cin, specialization);
        
        auto start = chrono::high_resolution_clock::now();
        vector<int> result = bfsTrainerSearch(specialization);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        
        cout << "[BFS] Total search time: " << duration.count() << " microseconds" << endl;
        cout << "[BFS] Space Complexity: O(V)" << endl;
        
        if (!result.empty()) {
            cout << "\n=== TRAINERS FOUND WITH SPECIALIZATION: " << specialization << " ===" << endl;
            for (int index : result) {
                trainers[index].displayTrainer();
            }
        } else {
            cout << "\nNo trainers found with specialization: " << specialization << endl;
        }
    }

    // NEW: ALGORITHM PERFORMANCE COMPARISON
    void algorithmPerformanceDemo() {
        cout << "\n=== ALGORITHM PERFORMANCE DEMONSTRATION ===" << endl;
        cout << "This demo compares Linear Search vs Binary Search performance" << endl;
        
        if (members.size() < 3) {
            cout << "Need at least 3 members for meaningful comparison. Add more members first." << endl;
            return;
        }
        
        // Search for the last member using both algorithms
        int targetId = members.back().getId();
        cout << "\nSearching for Member ID: " << targetId << endl;
        cout << "Dataset size: " << members.size() << " members" << endl;
        
        cout << "\n--- LINEAR SEARCH PERFORMANCE ---" << endl;
        auto start1 = chrono::high_resolution_clock::now();
        int linearResult = -1;
        for (int i = 0; i < members.size(); i++) {
            if (members[i].getId() == targetId) {
                linearResult = i;
                break;
            }
        }
        auto end1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
        cout << "Linear Search Time: " << duration1.count() << " microseconds" << endl;
        cout << "Comparisons made: " << linearResult + 1 << endl;
        
        cout << "\n--- BINARY SEARCH PERFORMANCE ---" << endl;
        vector<Member> sortedMembers = members;
        quickSort(sortedMembers, 0, sortedMembers.size() - 1, "id");
        
        auto start2 = chrono::high_resolution_clock::now();
        int binaryResult = binarySearch(sortedMembers, targetId);
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
        
        cout << "\n--- PERFORMANCE COMPARISON ---" << endl;
        cout << "Linear Search: O(n) - " << duration1.count() << " microseconds" << endl;
        cout << "Binary Search: O(log n) - " << duration2.count() << " microseconds" << endl;
        
        if (duration1.count() > duration2.count()) {
            cout << "Binary Search was " << (double)duration1.count()/duration2.count() 
                 << "x faster!" << endl;
        } else {
            cout << "Performance difference minimal due to small dataset size." << endl;
        }
        
        cout << "\nNote: Binary search requires sorted data (additional O(n log n) cost)" << endl;
        cout << "Linear search works on unsorted data but is slower for large datasets" << endl;
    }

    void displayMembershipPlans() {
        cout << "\n=== MEMBERSHIP PLANS ===" << endl;
        for (const auto& plan : membershipPlans) {
            plan.displayPlan();
        }
    }

    void addMembershipPlan() {
        string name, benefits;
        int duration;
        double price;
        
        cout << "Enter plan name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter duration (months): ";
        cin >> duration;
        cout << "Enter price: $";
        cin >> price;
        cout << "Enter benefits: ";
        cin.ignore();
        getline(cin, benefits);

        MembershipPlan newPlan(nextPlanId++, name, duration, price, benefits);
        membershipPlans.push_back(newPlan);
        cout << "Membership plan added successfully with ID: " << nextPlanId - 1 << endl;
    }

    void addMember() {
        string name, email, phone, shift, date;
        int planId;
        
        cout << "Enter member name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter email: ";
        getline(cin, email);
        
        if (memberEmailIndex.find(email) != memberEmailIndex.end()) {
            cout << "Email already exists! Please use a different email." << endl;
            return;
        }
        
        cout << "Enter phone: ";
        getline(cin, phone);
        
        displayMembershipPlans();
        cout << "Enter membership plan ID: ";
        cin >> planId;
        
        cout << "Select shift:" << endl;
        cout << "1. Morning (6:00 AM - 12:00 PM)" << endl;
        cout << "2. Evening (4:00 PM - 10:00 PM)" << endl;
        cout << "3. Full Day (6:00 AM - 10:00 PM)" << endl;
        cout << "Enter choice (1-3): ";
        int shiftChoice;
        cin >> shiftChoice;
        
        switch(shiftChoice) {
            case 1: shift = "Morning"; break;
            case 2: shift = "Evening"; break;
            case 3: shift = "Full Day"; break;
            default: shift = "Morning"; break;
        }
        
        cout << "Enter join date (DD/MM/YYYY): ";
        cin.ignore();
        getline(cin, date);

        Member newMember(nextMemberId++, name, email, phone, planId, shift, date);
        members.push_back(newMember);
        updateHashMaps();
        cout << "Member added successfully with ID: " << nextMemberId - 1 << endl;
        cout << "Hash Map Performance: O(1) lookup time achieved!" << endl;
    }

    void displayMembers() {
        if (members.empty()) {
            cout << "No members found!" << endl;
            return;
        }
        cout << "\n=== MEMBERS LIST ===" << endl;
        for (const auto& member : members) {
            member.displayMember();
        }
    }

    void displayMembersByShift() {
        string shift;
        cout << "Enter shift (Morning/Evening/Full Day): ";
        cin.ignore();
        getline(cin, shift);
        
        cout << "\n=== MEMBERS IN " << shift << " SHIFT ===" << endl;
        auto it = shiftMembers.find(shift);
        if (it != shiftMembers.end()) {
            for (int index : it->second) {
                if (members[index].getStatus()) {
                    members[index].displayMember();
                }
            }
            cout << "Hash Map Performance: O(1) shift lookup completed!" << endl;
        } else {
            cout << "No active members found in " << shift << " shift!" << endl;
        }
    }

    void searchMember() {
        cout << "Search by:" << endl;
        cout << "1. Member ID" << endl;
        cout << "2. Email" << endl;
        cout << "Enter choice (1-2): ";
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            int id;
            cout << "Enter member ID: ";
            cin >> id;
            
            auto it = memberIndex.find(id);
            if (it != memberIndex.end()) {
                cout << "\nMember found (O(1) Hash Map lookup):" << endl;
                members[it->second].displayMember();
            } else {
                cout << "Member not found!" << endl;
            }
        } else if (choice == 2) {
            string email;
            cout << "Enter email: ";
            cin.ignore();
            getline(cin, email);
            
            auto it = memberEmailIndex.find(email);
            if (it != memberEmailIndex.end()) {
                cout << "\nMember found (O(1) Hash Map lookup):" << endl;
                members[it->second].displayMember();
            } else {
                cout << "Member not found!" << endl;
            }
        }
    }

    void addTrainer() {
        string name, specialization, phone, shift, date;
        double salary;
        
        cout << "Enter trainer name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter specialization: ";
        getline(cin, specialization);
        cout << "Enter phone: ";
        getline(cin, phone);
        cout << "Enter salary: $";
        cin >> salary;
        
        cout << "Select shift:" << endl;
        cout << "1. Morning (6:00 AM - 2:00 PM)" << endl;
        cout << "2. Evening (2:00 PM - 10:00 PM)" << endl;
        cout << "3. Full Day (6:00 AM - 10:00 PM)" << endl;
        cout << "Enter choice (1-3): ";
        int shiftChoice;
        cin >> shiftChoice;
        
        switch(shiftChoice) {
            case 1: shift = "Morning"; break;
            case 2: shift = "Evening"; break;
            case 3: shift = "Full Day"; break;
            default: shift = "Morning"; break;
        }
        
        cout << "Enter join date (DD/MM/YYYY): ";
        cin.ignore();
        getline(cin, date);

        Trainer newTrainer(nextTrainerId++, name, specialization, phone, salary, shift, date);
        trainers.push_back(newTrainer);
        updateHashMaps();
        cout << "Trainer added successfully with ID: " << nextTrainerId - 1 << endl;
    }

    void displayTrainers() {
        if (trainers.empty()) {
            cout << "No trainers found!" << endl;
            return;
        }
        cout << "\n=== TRAINERS LIST ===" << endl;
        for (const auto& trainer : trainers) {
            trainer.displayTrainer();
        }
    }

    void displayTrainersByShift() {
        string shift;
        cout << "Enter shift (Morning/Evening/Full Day): ";
        cin.ignore();
        getline(cin, shift);
        
        cout << "\n=== TRAINERS IN " << shift << " SHIFT ===" << endl;
        auto it = shiftTrainers.find(shift);
        if (it != shiftTrainers.end()) {
            for (int index : it->second) {
                if (trainers[index].getAvailability()) {
                    trainers[index].displayTrainer();
                }
            }
            cout << "Hash Map Performance: O(1) shift lookup completed!" << endl;
        } else {
            cout << "No available trainers found in " << shift << " shift!" << endl;
        }
    }

    void addEquipment() {
        string name, category, date;
        double cost;
        
        cout << "Enter equipment name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter category: ";
        getline(cin, category);
        cout << "Enter purchase date (DD/MM/YYYY): ";
        getline(cin, date);
        cout << "Enter cost: $";
        cin >> cost;

        Equipment newEquipment(nextEquipmentId++, name, category, date, cost);
        equipments.push_back(newEquipment);
        cout << "Equipment added successfully with ID: " << nextEquipmentId - 1 << endl;
    }

    void displayEquipments() {
        if (equipments.empty()) {
            cout << "No equipment found!" << endl;
            return;
        }
        cout << "\n=== EQUIPMENT LIST ===" << endl;
        for (const auto& equipment : equipments) {
            equipment.displayEquipment();
        }
    }

    void deleteMember() {
        int id;
        cout << "Enter member ID to delete: ";
        cin >> id;
        
        auto it = memberIndex.find(id);
        if (it != memberIndex.end()) {
            members.erase(members.begin() + it->second);
            updateHashMaps();
            cout << "Member deleted successfully using Hash Map O(1) lookup!" << endl;
        } else {
            cout << "Member not found!" << endl;
        }
    }

    void generateReport() {
        cout << "\n=== GYM MANAGEMENT REPORT ===" << endl;
        cout << "Total Members: " << members.size() << endl;
        cout << "Total Trainers: " << trainers.size() << endl;
        cout << "Total Equipment: " << equipments.size() << endl;
        cout << "Total Membership Plans: " << membershipPlans.size() << endl;
        
        int morningMembers = shiftMembers["Morning"].size();
        int eveningMembers = shiftMembers["Evening"].size();
        int fullDayMembers = shiftMembers["Full Day"].size();
        int morningTrainers = shiftTrainers["Morning"].size();
        int eveningTrainers = shiftTrainers["Evening"].size();
        int fullDayTrainers = shiftTrainers["Full Day"].size();
        
        double totalRevenue = 0;
        for (const auto& member : members) {
            if (member.getStatus()) {
                auto planIt = find_if(membershipPlans.begin(), membershipPlans.end(),
                    [&member](const MembershipPlan& p) { return p.getId() == member.getMembershipPlanId(); });
                if (planIt != membershipPlans.end()) {
                    totalRevenue += planIt->getPrice();
                }
            }
        }
        
        double totalSalary = 0;
        for (const auto& trainer : trainers) {
            totalSalary += trainer.getSalary();
        }
        
        cout << "\n--- SHIFT DISTRIBUTION (Hash Map O(1) Access) ---" << endl;
        cout << "Morning Shift - Members: " << morningMembers << " | Trainers: " << morningTrainers << endl;
        cout << "Evening Shift - Members: " << eveningMembers << " | Trainers: " << eveningTrainers << endl;
        cout << "Full Day Shift - Members: " << fullDayMembers << " | Trainers: " << fullDayTrainers << endl;
        
        cout << "\n--- FINANCIAL REPORT ---" << endl;
        cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << endl;
        cout << "Total Expenses (Salaries): $" << fixed << setprecision(2) << totalSalary << endl;
        cout << "Net Profit: $" << fixed << setprecision(2) << (totalRevenue - totalSalary) << endl;
        
        cout << "\n--- ALGORITHM PERFORMANCE SUMMARY ---" << endl;
        cout << "Hash Map Lookups: O(1) average time complexity" << endl;
        cout << "Quick Sort: O(n log n) average, O(n²) worst case" << endl;
        cout << "Merge Sort: O(n log n) guaranteed" << endl;
        cout << "Linear Search: O(n) time complexity" << endl;
        cout << "Binary Search: O(log n) time complexity" << endl;
        cout << "DFS/BFS: O(V + E) time complexity" << endl;
    }

    void showAlgorithmMenu() {
        cout << "\n=== SORTING & SEARCHING ALGORITHMS DEMO ===" << endl;
        cout << "15. Sort Members (Quick Sort)" << endl;
        cout << "16. Sort Trainers by Salary (Merge Sort)" << endl;
        cout << "17. Advanced Linear Search" << endl;
        cout << "18. Binary Search Members" << endl;
        cout << "19. DFS Equipment Search by Category" << endl;
        cout << "20. BFS Trainer Search by Specialization" << endl;
        cout << "21. Algorithm Performance Comparison" << endl;
        cout << "22. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
    }

    void showMenu() {
        cout << "\n=== GYM MANAGEMENT SYSTEM  ===" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Display All Members" << endl;
        cout << "3. Display Members by Shift" << endl;
        cout << "4. Search Member (Hash Map O(1))" << endl;
        cout << "5. Delete Member" << endl;
        cout << "6. Add Trainer" << endl;
        cout << "7. Display All Trainers" << endl;
        cout << "8. Display Trainers by Shift" << endl;
        cout << "9. Add Equipment" << endl;
        cout << "10. Display All Equipment" << endl;
        cout << "11. Display Membership Plans" << endl;
        cout << "12. Add Membership Plan" << endl;
        cout << "13. Generate Report" << endl;
        cout << "14. Sorting & Searching Algorithms Demo" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void run() {
        int choice;
        do {
            showMenu();
            cin >> choice;
            
            switch (choice) {
                case 1: addMember(); break;
                case 2: displayMembers(); break;
                case 3: displayMembersByShift(); break;
                case 4: searchMember(); break;
                case 5: deleteMember(); break;
                case 6: addTrainer(); break;
                case 7: displayTrainers(); break;
                case 8: displayTrainersByShift(); break;
                case 9: addEquipment(); break;
                case 10: displayEquipments(); break;
                case 11: displayMembershipPlans(); break;
                case 12: addMembershipPlan(); break;
                case 13: generateReport(); break;
                case 14: 
                    {
                        int algoChoice;
                        do {
                            showAlgorithmMenu();
                            cin >> algoChoice;
                            
                            switch (algoChoice) {
                                case 15: sortMembers(); break;
                                case 16: sortTrainers(); break;
                                case 17: advancedLinearSearch(); break;
                                case 18: binarySearchMembers(); break;
                                case 19: dfsEquipmentCategorySearch(); break;
                                case 20: bfsTrainerSpecializationSearch(); break;
                                case 21: algorithmPerformanceDemo(); break;
                                case 22: cout << "Returning to main menu..." << endl; break;
                                default: cout << "Invalid choice! Please try again." << endl;
                            }
                        } while (algoChoice != 22);
                    }
                    break;
                case 0: cout << "Thank you for using Enhanced Gym Management System!" << endl; break;
                default: cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    cout << "=== ENHANCED GYM MANAGEMENT SYSTEM ===" << endl;
    cout << "Featuring Advanced Sorting & Searching Algorithms:" << endl;
    cout << " Quick Sort & Merge Sort" << endl;  
    cout << " Linear Search & Binary Search" << endl;
    cout << " Depth-First Search (DFS) & Breadth-First Search (BFS)" << endl;
    cout << " Hash Map optimizations for O(1) lookups" << endl;
    cout << " Performance analysis and time complexity demonstrations" << endl;
    cout << "\nSample data has been pre-loaded for algorithm demonstrations." << endl;
    cout << "=========================================" << endl;
    
    GymManagementSystem gym;
    gym.run();
    return 0;
}