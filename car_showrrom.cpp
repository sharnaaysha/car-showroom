#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 100
#define password 12456
using namespace std;

int total_car;//like count
class car_showroom
{
public:
	char car_name[N];
	char car_model[N];
	char car_zip_code[N];
	int car_price;
	char car_country_made[N];
	int stock;

};

class car_management:public car_showroom
{
public:
	car_showroom store[N];
	void adding();
	void display_all();
	void removing();
	void save();
	void search();
	void buy();
	car_management()
	{
		FILE *tc;
		tc = fopen("Total Car.txt","r");
		fscanf(tc,"%d",&total_car);
		cout<<total_car<<endl;
		fclose(tc);
		int i;
		FILE *nn;
		nn = fopen("Cars Name.txt","r");
		for(i=0;i<total_car;i++)
		{
			fscanf(nn,"%s",&store[i].car_name);
		}
		fclose(nn);
		FILE *mm;
		mm = fopen("Cars model.txt","r");
		for(i=0;i<total_car;i++)
		{
			fscanf(mm,"%s",&store[i].car_model);
		}
		fclose(mm);
		FILE *pp;
		pp = fopen("Cars price.txt","r");
		for(i=0;i<total_car;i++)
		{
			fscanf(pp,"%d",&store[i].car_price);
		}
		fclose(pp);
		FILE *st;
		st = fopen("Cars stock.txt","r");
		for(i=0;i<total_car;i++)
		{
			fscanf(st,"%d",&store[i].stock);
		}
		fclose(st);

		FILE *zz;
		zz = fopen("Cars zip code.txt","r");
		for(i=0;i<total_car;i++)
		{
			fscanf(zz,"%s",&store[i].car_zip_code);
		}
		fclose(zz);
		FILE *cc;
		cc = fopen("Cars country made.txt","r");
		for( i=0;i<total_car;i++)
		{
			fscanf(cc,"%s",&store[i].car_country_made);
		}
		fclose(cc);
	}

};
void car_management::adding()
{
	cout<<"Give name: ";
	cin.getline(store[total_car].car_name,N);
	cout<<"Give Model";
	cin.getline(store[total_car].car_model,N);
	cout<<"Give Zic code";
	cin.getline(store[total_car].car_zip_code,N);
	cout<<"Give price";
	cin>>store[total_car].car_price;
	getchar();
	cout<<"Give stock of car: ";
	cin>>store[total_car].stock;
	getchar();
	cout<<"Give country made";
	cin.getline(store[total_car].car_country_made,N);
	total_car++;

}

void car_management::display_all()
{
	cout<<total_car;
	for(int i=0;i<total_car;i++)
	{

		cout<<"-----------car "<<i+1<<"--------------\n";
		cout<<"|    Car name: ";
		cout<<store[i].car_name<<endl;

		cout<<"|    Car model: ";
		cout<<store[i].car_model<<endl;

		cout<<"|    Car zip code: ";
		cout<<store[i].car_zip_code<<endl;

		cout<<"|    Car price: ";
		cout<<store[i].car_price<<endl;
		cout<<"|    Number of available : ";
		cout<<store[i].stock<<endl;
		cout<<"|    Car country made: ";
		cout<<store[i].car_country_made<<endl;
		cout<<"-------------------------------\n\n";
	}
}
void car_management::removing()
{
	printf("Press 1 for delete all and 2 for delete 1 car\n");
	int s,i;
	scanf("%d",&s);
	getchar();
	if(s==1)total_car=0;
	else
	{
		char carname[N];
		cout<<"Give name to remove: ";
		cin>>carname;
		for(int i=0;i<total_car;i++)
		{
			if(strcmp(carname,store[i].car_name)==0)
			{
				break;
			}
		}
		for(int j=i+1;j<total_car;j++)
			store[j-1]=store[j];
		total_car--;
	}
}
void car_management::search()
{
	char carname[N];
	cout<<"Give name for search: ";
	cin.getline(carname,N);
	for(int i=0;i<total_car;i++)
	{
		if(strcmp(carname,store[i].car_name)==0)
		{
			cout<<"-----------car "<<i+1<<"--------------\n";
			cout<<"|    Car name: ";
			cout<<store[i].car_name<<endl;

			cout<<"|    Car model: ";
			cout<<store[i].car_model<<endl;

			cout<<"|    Car zip code: ";
			cout<<store[i].car_zip_code<<endl;

			cout<<"|    Car price: ";
			cout<<store[i].car_price<<endl;
			cout<<"|    Number of available : ";
			cout<<store[i].stock<<endl;
			cout<<"|    Car country made: ";
			cout<<store[i].car_country_made<<endl;
			cout<<"-------------------------------\n\n";
		}
	}

}

void car_management::buy()
{
	char carname[N],carmodel[N];
	int num,have=0;
	cout<<"Give name for buy: ";
	cin.getline(carname,N);
	cout<<"Give model for "<<carname<<" : ";
	cin.getline(carmodel,N);
	for(int i=0;i<total_car;i++)
	{
		if(strcmp(carname,store[i].car_name)==0 && strcmp(carmodel,store[i].car_model)==0  )
		{
			have=1;
			cout<<"-----------car "<<i+1<<"--------------\n";
			cout<<"|    Car name: ";
			cout<<store[i].car_name<<endl;

			cout<<"|    Car model: ";
			cout<<store[i].car_model<<endl;

			cout<<"|    Car zip code: ";
			cout<<store[i].car_zip_code<<endl;

			cout<<"|    Car price: ";
			cout<<store[i].car_price<<endl;
			cout<<"|    Number of available : ";
			cout<<store[i].stock<<endl;
			cout<<"|    Car country made: ";
			cout<<store[i].car_country_made<<endl;
			cout<<"-------------------------------\n\n";
			cout<<"How many car do you want to buy: ";
			cin>>num;
			if(num<=store[i].stock)
			{

				cout<<"Total money : ";
				cout<<num*store[i].car_price;
				cout<<" \nThanks for buying\n";
				store[i].stock-=num;
			}
			else
				cout<<"Do not have enough stock"<<endl;
		}
	}
	if(have==0)
		cout<<"We do not have the car\n";

}

void car_management::save()
{
	int i;
	FILE *tc;
	tc = fopen("Total Car.txt","w");
	fprintf(tc,"%d\n",total_car);
	fclose(tc);
	FILE *n;
	n = fopen("Cars Name.txt","w");
	for(i=0;i<total_car;i++)
	{
		fprintf(n,"%s\n",store[i].car_name);
	}
	fclose(n);
	FILE *m;
	m = fopen("Cars model.txt","w");
	for(i=0;i<total_car;i++)
	{
		fprintf(m,"%s\n",store[i].car_model);
	}
	fclose(m);
	FILE *p;
	p = fopen("Cars price.txt","w");

	for(i=0;i<total_car;i++)
	{
		fprintf(p,"%d\n",store[i].car_price);
	}
	fclose(p);
	FILE *st;
	st = fopen("Cars stock.txt","w");

	for(i=0;i<total_car;i++)
	{
		fprintf(st,"%d\n",store[i].stock);
	}
	fclose(st);
	FILE *z;
	z = fopen("Cars zip code.txt","w");
	for(i=0;i<total_car;i++)
	{
		fprintf(z,"%s\n",store[i].car_zip_code);
	}
	fclose(z);
	FILE *c;
	c = fopen("Cars country made.txt","w");
	for( i=0;i<total_car;i++)
	{
		fprintf(c,"%s\n",store[i].car_country_made);
	}
	fclose(c);
}
int main()
{
	int x,pass;
	car_management car;
	while(1)
	{	cout<<"enter your choice"<<endl;
		cout<<"._________. .___________. .___________. ._________. ._________. .__________.   \n";
		cout<<"|         | |           | |           | |         | |         | |          |   \n";
		cout<<"| Press 1 | |  Press 2  | |  Press 3  | | Press 4 | | Press 5 | | press 6  |   \n";
		cout<<"|   for   | |    for    | |for showing| |  for    | |  for    | |   for    |   \n";
		cout<<"|   Add   | |  delete   | |  all car  | | search  | |  buy    | |   exit   |   \n";
		cout<<"|_________| |___________| |___________| |_________| |_________| |__________|   \n";
		cin>>x;
		getchar();
		if(x==1)
		{
			cout<<"Give password: "<<endl;
			cin>>pass;
			getchar();
		    if(password==pass)
				car.adding();
			else
				cout<<"Wrong password try again..."<<endl;
		}
		else if(x==2)
		{
			cout<<"Give password: ";
			cin>>pass;
			getchar();
			if(password==pass)
		   car.removing();
			else
				cout<<"Wrong password try again..."<<endl;
		}
		else if(x==3)
		{
			car.display_all();
		}
		else if(x==4)
		{
			car.search();
		}
		 else if(x==5)
		{
			car.buy();
		}
		 else if(x==6)
		 {
			 break;
		 }
	}

	car.save();
	return 0;
}
