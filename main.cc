/*****************************************************************
	This is the main for our first project. Having a uniform menu 
	makes my grading much easier, so please use this for your 
	project. You should also have your data stored in the same 
        format as the sample that I give you.
	    John Dolan	Ohio University EECS 	Spring 2020
 	
	I have provided some numbers to guide you in the step-step development
	of this program. Uncomment each as you write the function.
*******************************************************************/
#include<iostream>
#include<fstream>
#include "runtime.h"
#include "runjournal.h"
using namespace std;

// Function menu presents menu to user and collects a selection
int menu();

int main( ){
	Runtime tmp;
// Test your input and output operators with this:
/*
  	cout << "Enter a run: ";
    cin >> tmp;
    cout << "Here it is: ";
    cout << tmp << endl;
    cout << "Good-bye.\n";
*/
   	Runjournal myruns; 
    ifstream ifs;
    ofstream ofs;
    int choice;
    double dist;

	ifs.open("runlog.txt");
    if(!ifs.fail()){
		ifs >> tmp;
		while(!ifs.eof()){
	    	myruns.record(tmp);
	   	 	ifs >> tmp;
		}
	ifs.close();
	}

    do{
	choice = menu();
	switch(choice){
		case 1: 
			cin >> tmp;
			myruns.record(tmp);  
			break;
		case 2:  
			cin >> tmp;
			myruns.find_remove(tmp);  
			break;
		case 3:		
			myruns.display(); 
			break;
		case 4:		
			cin >> dist;
			myruns.distance_view(dist); 
			break;
		case 5:	
			myruns.time_sort(); 
			myruns.display();
			break;
		case 6:		
			myruns.distance_sort(); 
			myruns.display();
			break;
		case 7:  	
			cout << myruns.total_time() << endl; 
			break;
		case 8: 	
			cout << myruns.total_distance() << endl; 
			break;		
		case 9: 
			cout << myruns.average_pace() << endl; 
			break;
		case 0: 
			cout  << "Thank you for using our software.\n";
			break;		
		default: 
			cout << "Not a valid selection.\n";
			break;
			} 
    }while(choice != 0);

//file saving

	ofs.open("runlog.txt");
	if(!ofs.fail()){
	    myruns.save(ofs); 
	    ofs.close();
 	}

return 0;
}

int menu( ){
    int selection;
    cout<<"Chose from the Following\n";
    cout<<"1.) RECORD a run\n";
    cout<<"2.) FIND a run by entering time and distance w option to remove\n";
    cout<<"3.) VIEW all the runs in the Journal\n";
    cout<<"4.) DISPLAY runs of a specific distance\n";
    cout<<"5.) SORT by TIME\n";
    cout<<"6.) SORT by DISTANCE\n";
    cout<<"7.) TOTAL TIME\n";
    cout<<"8.) TOTAL DISTANCE\n";
    cout<<"9.) AVERAGE PACE\n";
    cout<<"0.) QUIT\n";
	cout << "Enter your choice here: ";
    cin >> selection;
    return selection;
}
