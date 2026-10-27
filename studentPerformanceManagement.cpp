#include <iostream>
using namespace std;

//Class to manage the student scores
class StudentScore
{
private:
	//Stores the number of students
	int numStudents;
	//Dynamically allocated array to store the scores of students
	int* scores;

public:
	//Constructor to initialize the array based on the number of students
	StudentScore(int n);

	//Destructor to free the dynamically allocated memory
	~StudentScore();

	//Function to input the scores of students
	void inputStudentScore();

	//Determine the maximum score
	int getMaxScore();

    //Determine the minimum score
	int getMinScore();

	//Calculate the average score
	double getAverageScore();

};

//A basic view showing only the maximum score
void displayMaxScore(int maxScore);

//A detailed report showing maximum, minimum, and average scores
void displayDetailedReport(int maxScore, int minScore, double avgScore);

int main()
{
	int numberOfStudents;

	cout << "Welcome to the Student Performance Management System!" << endl;
	cout << "Please enter the number of students in the class: ";
	cin >> numberOfStudents;

	//Create an object of StudentScore class
	StudentScore studentScores(numberOfStudents);

	//Input the scores of students
	studentScores.inputStudentScore();

	//Calculate the statistics of the scores
	int maxScore = studentScores.getMaxScore();
	int minScore = studentScores.getMinScore();
	double avgScore = studentScores.getAverageScore();

	//Display the results
	displayMaxScore(maxScore);
	displayDetailedReport(maxScore, minScore, avgScore);

	return 0;
}

StudentScore::StudentScore(int n)
{
	//Initialize the number of students 
	this->numStudents = n;
	//Dynamically allocate memory for the scores array
	this->scores = new int[numStudents];
}

StudentScore::~StudentScore()
{
	delete[] scores;
}

//Function to input the scores of students
void StudentScore::inputStudentScore()
{
	cout << "\nEnter the scores:\n";
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Student: " << (i + 1) << ": ";
		cin >> scores[i];
	}
}

//Determine the maximum score
int StudentScore::getMaxScore() 
{
	int maximumScore = scores[0];
	for (int i = 1; i < numStudents; i++)
	{
		if(scores[i] > maximumScore)
			maximumScore = scores[i];	
	}
	return maximumScore;
}

//Determine the minimum score
int StudentScore::getMinScore()
{
	int minimumScore = scores[0];
	for (int i = 1; i < numStudents; i++)
	{
		if(scores[i] < minimumScore)
			minimumScore = scores[i];
	}
	return minimumScore;
}

//Calculate the average score
double StudentScore::getAverageScore()
{
	int  sumScore = 0;
	for (int i = 0; i < numStudents; i++)
		sumScore += scores[i];
	
	return static_cast<double>(sumScore) /numStudents;
	
}

//A basic view showing only the maximum score
void displayMaxScore(int maxScore)
{
	cout << "\nThe maximum score is: " << maxScore << endl;
}

//A detailed report showing maximum, minimum, and average scores
void displayDetailedReport(int maxScore, int minScore, double avgScore)
{
	cout << "\nDetailed Report:\n";
	cout << "Maximum Score: " << maxScore << endl;
	cout << "Minimum Score: " << minScore << endl;
	cout << "Average Score: " << avgScore << endl;
}
