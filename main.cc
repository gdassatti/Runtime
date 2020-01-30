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
	//string filename;
/*
	cout << endl;
	cout << "Please enter the name of the file you would like to work with: ";
	cin >> filename;
*/

  
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

					cout << "Enter the run here with spaces in between: ";
					cin >> tmp;
					myruns.record(tmp);  
					break;
		
			case 2:  

					cout << "Enter the time and distance of the run here: ";
					cin >> tmp;
					myruns.find_remove(tmp);  
					break;
		
			case 3:	
			
					cout << endl;
					myruns.display(); 
					cout << endl;
					break;
		
			case 4:	
			
					cout << endl;
					cout << "Enter a distance to view: ";
					cin >> dist;
					myruns.distance_view(dist); 
					cout << endl;
					break;
		
			case 5:	
			
					myruns.time_sort(); 
					cout << endl;
					myruns.display();
					cout << endl;
					break;
		
			case 6:	
			
					myruns.distance_sort(); 
					cout << endl;
					myruns.display();
					cout << endl;
					break;
		
			case 7:  
			
					cout << endl;
					cout << "Total time: " << myruns.total_time() << endl; 
					cout << endl;
					break;
		
			case 8: 
			
					cout << endl;
					cout << "Total distance: " << myruns.total_distance() << " miles" << endl; 
					cout << endl;
					break;
		
			case 9: 
			
					cout << endl;
					cout << "Average pace: " << myruns.average_pace() << " per mile." << endl; 
					cout << endl;
					break;
		
			case 0: 

					cout << endl;
					cout  << "Thank you for using our software.\n";
					cout << endl;
					break;
			
			default: 
			
					cout << endl;
					cout << "Not a valid selection.\n";
					break;

			} // bottom of the switch

    } while(choice != 0);

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

	cout << endl;
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
