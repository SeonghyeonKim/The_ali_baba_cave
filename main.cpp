// Make ‘The Ali Baba Cave’.
#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;

// have_key : if you have a decryption key. 0:no. 1:yes.
// the_number_of_case : upper than 1, lower than 100001. 
int have_key, the_number_of_case=1;

// print title
// parameter : None
// return : None
void printTitle(void) {
	cout << "\n==============================\n";
	cout << "========The Ali Baba Cave========\n";
	cout << "==============================\n";
}

// print menu
// parameter : None
// return : None
void printMenu(void) {
    cout << "\n============MENU============\n";
    cout << "1. Print State\n";
    cout << "2. Set State\n";
    cout << "3. Test\n";
    cout << "4. Quit\n";
}

// print current state
// parameter : None
// return : None
// print possesion of key and the number of test case
void printState(void) {
    if(have_key) cout << "\nYou have a key\n";
    else cout << "\nYou don’t have a key\n";

    cout << "The number of testcase : " << the_number_of_case << "\n";
}

// Setting State
// parameter : None
// return : None
// input Key state and the number of test case
void setState(void) {
    //Key state
    while(1) {
        cout << "\nInput key state.\n";
        cout << "1. have  2. don’t have\n >>> ";
        
        int num;
        cin >> num;

        if(num==1) {
            have_key=1;
            cout << "\nNow, you have a key\n";
            break;
        }
        else if(num==2) {
            have_key=0;
            cout << "\nNow, you don’t have a key\n";
            break;
        }
        else cout << "\nWrong State!\n";
    } 

    // the number of test case
    while(1) {
        cout << "\nInput the number of case\n";
        cout << "You can input 1 to 100000\n";
        cout << ">>> ";
        int num;
        cin >> num;
        if(num>0 && num<=100000) {
            the_number_of_case = num;
            cout << "\nCurrent Test Case : " << num;
            break;
        }
        else cout << "\nWrong State!\n";
    }
}

// Ali Baba Case Test
// parmeter : None
// return : None
// test the zero-knowledge proof
void test(void) {
    int complete_count=0;

    // random
    random_device rd; 
    mt19937_64 mt(rd());
    uniform_int_distribution<int> range(0, 1);

    for(int i=1; i<=the_number_of_case; i++) {
        int check = range(mt);
        int choice = range(mt);

        char V, P;
        V = char(check+'A');
        if(have_key==0) P = char(choice+'A');
        else P = V;

        cout << "Victor : " << V << " Peggy : " << P << ". "; 

        if(V == P) {
            cout << "Case #" << i << " complete.\n";
            complete_count++;
        }
        else cout << "Case #" << i << " fail\n";
        
        usleep(500 * 1000);
    }

    cout << "\n#case = " << the_number_of_case << " #complete = " << complete_count;
    cout << " result = " << complete_count*100.0/the_number_of_case << "%\n";
}

// Input Menu
// parameter : None
// return : input number
int input(void) {
    cout << "\nSelect the number : ";
    int num;
    cin >> num;
    return num;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    printTitle();

    while(1) {
        printMenu();
        int selection = input();
            
        switch (selection) {
            case 1:
                printState();
                break;
            case 2:
                setState();
                break;
            case 3:
                test();
                break;
            case 4:
                exit(0);
            default:
                cout << "\nWrong selection!\n";
        }
    }
	
	return 0;
}
