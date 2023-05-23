

#include <iostream>

#include<fstream>

using namespace std;

class studentinfo
{
    public :

	int stnum;

	char password[20];

	char name[10];

	char family[15];


};

class vahedha
{
	public :

	int stnum;

	int lessnumber;
	
	char dars[10];

	int vahed;

};
//////////////////////////////

int main()
{
                                             ifstream info("info.dat" , ios::in);

	                                         ofstream info1("info.dat", ios::app);

	studentinfo stinfo; ////class instance

	int stnum;
	char password[20];

loginpage :

	cout << "**************************Welcome To Login Page *******************************\n\n";

	cout << "#### Student ID #### : ";       //////login page

	cin >> stnum;

	cout << "<<<< Password >>>> :";                                                                                    //////login page

	cin >> password;

	while (!info.eof())
	{
		info >> stinfo.stnum;

		info >> stinfo.password;

		if (stinfo.stnum == stnum)
		{
			if(strcmp(stinfo.password , password)==0)
			{
				info >> stinfo.name;

				info >> stinfo.family;

				system("cls");

				goto  studentpage;

			}
		}

		info >> stinfo.name;

		info >> stinfo.family;

	}
	cout << "!!!!!!!!!!!!!Student number Or Password Not Found !!!!!!!!!\n\n";

	cout << "..............Please Enter any key to continue ..........";

	char e;

	cin >> e;

	system("cls");

	goto loginpage;

////////////////////////////////////////////  Student Page  /////////////////////////////////////////////////////////////////////////////////////

studentpage :

	cout << "**************Hello Dear " << stinfo.name << " ****************\n\n";                                         ///////student page

	cout << "1) Entekhab Vahed <e> :\n\n";

	cout << "2) Mohasebe Moadel <m> :\n\n ";

	cout << "3) Nameyeshe Etelaat <ne>:\n\n";

	cout << "4) Virayeshe Etelaat <v> :\n\n";

	cin >> e;


////////////////////////////////  Entekhab Vahed    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (e == 'e')                                                                                                   ////entekhab vahed
	{
		                          ofstream vahed("vahed.dat", ios::app);
		                          ifstream rvahed("vahed.dat", ios::in);
		vahedha stvahed;



		while (!vahed.eof())
		{
			rvahed >> stvahed.stnum;
		

			if (stvahed.stnum == NULL)cout << "\nfile is empty!!!!!";


			if (stvahed.stnum == stinfo.stnum)///////check register precedence                                                       ///////check register precedence
			{
				cout << "\n!!!!!!!! Shoma Ghablan Entekhab Vahed Kardid !!!!!!!";
				
				cout << "\n\nEnter any key to continue....";

				cin >> e;

				system("cls");

				vahed.close();

				goto studentpage;
			}

			rvahed >> stvahed.lessnumber;

			for (int j = 0; j < stvahed.lessnumber; j++)
			{
				char temp[15];

				rvahed >> temp;
			}
		}

		

		cout << "Enter Your Student Number :\n";

		cin >> stvahed.stnum;

		vahed << stvahed.stnum;

		cout << "Enter lessons number :\n";

		cin >> stvahed.lessnumber;

		vahed << stvahed.lessnumber;

		for (int i = 0; i < stvahed.lessnumber;i++)

		{
			cout << "Lesson Name : ";

			cin >> stvahed.dars;

			vahed << stvahed.dars;

			cout << "Enter Unit Lesson :";

			cin >> stvahed.vahed;

			vahed << stvahed.vahed;

		}

		system("cls");

		cout << "...Succefully registered !!!!";

		cout << "\nEnter any key to continue.....";

		cin >> e;

		rvahed.close();

		vahed.close();

		goto studentpage;
	}

////////////////////// Namyeshe  Etelaat E Shakhs   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////namayeshe etelaat 

	if (e == 'ne')
	{
		system("cls");

		ofstream main("maininfo.dat", ios::app);

		ifstream info("info.dat", ios::in);

		ifstream rvahed("vahed.dat", ios::in);

		studentinfo stinfo;
		
		vahedha vahed;

		cout << "<<Personal Information>> \n";

		while (!info.eof())
		{
			info >> stinfo.stnum;

			cout << "Student Number : " << stinfo.stnum;

			info >> stinfo.password;

			cout << "Password :\n" << stinfo.password;

			info >> stinfo.name;

			info >> stinfo.family;

			cout << "Name :" << stinfo.name << " " << stinfo.family;

			cout << endl;
		}


		ifstream average("average.dat", ios::in);

		while (!average.eof())

		{
			int average1,stnum1;

			average >> stnum1;

			average >> average1;

			cout << average1;

		}


		cout << "<<Vahedha>> ";

		while (!rvahed.eof())
		{
			rvahed >> vahed.stnum;

			if (vahed.stnum == NULL){}
		   
			rvahed >> vahed.lessnumber;

			for (int j = 0; j < vahed.lessnumber; j++)
			{
				cout << "\nLesson Name :";

				vahed.dars;

				rvahed >> vahed.dars;

				cout << "\nLesson Unit :";

				rvahed >> vahed.vahed;

				cout << vahed.vahed;
				
			}
		}

	

		

	
	}

/////////////////////  Average  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Average

	if (e == 'm')
	{
		                                                 ofstream average("average.dat", ios::app);


		int i,sum=0,score;

		cout << "\nEnter Lessons Number : ";

		cin >> i;

		for (int j = 0; j < i; j++)
		{
			cout << "\nEnter Your  Score :";

			cin >> score;

			sum += score;
		}

		sum = sum / i ;

		cout << " Your Average is : " << sum ;

		average << stinfo.stnum<<endl;

		average << sum;
	}

	/////////////////////////////////virayesh////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// VIRAYESH

	if (e == 'v')
	{
		ofstream vahed("vahed.dat", ios::app);
		ifstream rvahed("vahed.dat", ios::in);

		int stunum;

		vahedha stvahed1[100];


		system("cls");

		cout << "Add or delete <a> or <d>: ";

		cin >> e;

		if (e == 'a')
		{
			int i = 0;

			while (!rvahed.eof())
			{
				rvahed >> stvahed1[i].stnum;

				rvahed >> stvahed1[i].lessnumber;

				for (int j = 0; j < stvahed1[i].lessnumber; j++)
				{

					rvahed >> stvahed1[j].dars;
					rvahed >> stvahed1[j].dars;

				}
			}
	


		}

		if(e=='d')
		{
		}

	}

}



