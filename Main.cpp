#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Function Declarations:
void MenuList();
double MainInput();
void Step1();
double Step2(double, double);
double Step3(double);
double Step4(double);
double Step5(double, double, double);

//Global Variables:
double gravity = 9.8;
#define PI 3.14159265

double velocity;
double angle;
double xmax;
double ymax;
double ttop;
double ttotal;

int main()
{
	int menu;
	
	MenuList();
	cout << "Please enter an option:" << endl;
	cin >> menu;

	while (menu != 2)
	{
		switch (menu)
		{
		case 1:
			MainInput();
			Step1();
			ymax = Step2(velocity, angle);
			ttop = Step3(ymax);
			ttotal = Step4(ttop);
			xmax = Step5(ttotal, velocity, angle);
			break;

		default:
			cout << "Invalid Choice" << endl;
			cin >> menu;
		}

		MenuList();
		cout << "Please enter an option:" << endl;
		cin >> menu;
	}

	return 0;
}

//Menu Function

void MenuList()
{
	cout << "1. Projectile Motion" << endl;
	cout << "2. Quit" << endl;

}

//Input Function

double MainInput()
{
	cout << "Please Enter Your Velocity Vector: ";
	cin >> velocity;

	cout << "Please Enter the Angle of Your Projectile In Degrees (between 0 and 90): ";
	cin >> angle;
	cout << endl;

	while (angle < 0 || angle > 90)
		{
		cout << "The angle must be a number between 0 and 90." << endl;
		cout << "Please re-enter your angle: " << endl;
		cin >> angle;
		}

	return (velocity, angle);
}

//Calculation Functions

void Step1()
{
	cout << "Step 1:  Write the Equations of Kinematics" << endl << endl;
	cout << "         V^2[fy] - v^2[oy] = 2a(Y[max] - Y[o])" << endl;
	cout << "         X[max] = X[o] + V[ox]t + 1/2at^2" << endl;
	cout << endl;
}

double Step2(double velocity, double angle)
{
	double sine_angle;
		
	cout << "Step 2: Determine Y[max] (The maximum height of the projectile)" << endl << endl;
	cout << "        V[fy] = V[o]sin(angle) = The sine of the angle of your projectile" << endl;

	sine_angle = sin(angle*PI / 180);

	cout << "        (V[o]sin(angle) * V)^2 /2a" << endl << endl;

	ymax = (pow((sine_angle * velocity), 2)) / (2 * gravity);

	cout << "Y[max] = " << ymax << endl;
	cout << endl;

	return ymax;
}

double Step3(double ymax)
{
	double ttopsquared;

	cout << "Step 3: Solve for Time to Top" << endl << endl;
	cout << "        t[top]^2 = Y[max] / 1/2 a[y], where a[y] = gravity" << endl << endl;
	
	ttopsquared = ymax / (.5 * gravity);
	ttop = sqrt(ttopsquared);

	cout << "Time to top = " << ttop << endl;
	cout << endl;

	return ttop;
}

double Step4(double ttop)
{

	cout << "Step 4: Solve for total time" << endl << endl;
	cout << "        t[total] = 2t[top]" << endl << endl;

	ttotal = 2 * ttop;

	cout << "Total Time = " << ttotal << endl;
	cout << endl;

	return ttotal;
}

double Step5(double ttotal, double velocity, double angle)
{
	double cos_angle;
		
	cout << "Step 5: Plug t[total] and V[ox] = V[o]cos(angle) into equation 2" << endl << endl;
	cout << "        Equation 2 = X[max] = X[o] + V[ox]t + 1/2at^2" << endl;
	cout << "        Because the projectile is being launched from the origin, X[o] = 0" << endl;
	cout << "        Because the velocity is constant and not changing, acceleration must equal 0" << endl;
	cout << "              Because gravity is a[y], which equals 9.8, a[x] must equal 0 for a[x] * a[y] to = 0" << endl;
	cout << "        This means that the left and right sides of the equation = 0" << endl;
	cout << "              and the middle part is the only one that needs to be calculated" << endl << endl;

	cos_angle = cos(angle * (PI / 180));
	xmax = velocity * cos_angle * ttotal;

	cout << "The maximum distance that a projectile moving at " << velocity <<
		" meters/second at a " << angle << " degree angle travels is: " <<
		fixed << setprecision(4) << xmax << " meters." << endl;
	cout << endl;

	return xmax;
}
