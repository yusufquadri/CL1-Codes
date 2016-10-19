// Author: Khalid - naam toh suna hi hoga
// Steps to run ->
// :~$ g++ yoyo.cpp
// :~$ ./a.out

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
  float points[50][4]; // resolves stack smashing error - credits to Navin Mutha
  // The first column will have the x co-ordinates
  // The second column will have the y co-ordinates
  // The third column will have the height characteristics - 0 for short, 1 for average, 2 for tall
  // The fourth column will have the distance to the point to be considered - this will be calculated

  // brace yourselves - their's gonna be a lot of initializing

  points[0][0] = 1;
  points[0][1] = 1;
  points[0][2] = 0;

  points[1][0] = 1;
  points[1][1] = 2;
  points[1][2] = 0;

  points[2][0] = 1;
  points[2][1] = 3;
  points[2][2] = 0;

  points[3][0] = 1;
  points[3][1] = 4;
  points[3][2] = 0;

  points[4][0] = 1;
  points[4][1] = 5;
  points[4][2] = 0;

  points[5][0] = 1;
  points[5][1] = 6;
  points[5][2] = 0;

  points[6][0] = 1;
  points[6][1] = 7;
  points[6][2] = 0;

  points[7][0] = 2;
  points[7][1] = 1;
  points[7][2] = 0;

  points[8][0] = 2;
  points[8][1] = 2;
  points[8][2] = 0;

  points[9][0] = 2;
  points[9][1] = 3;
  points[9][2] = 1;

  points[10][0] = 2;
  points[10][1] = 4;
  points[10][2] = 1;

  points[11][0] = 2;
  points[11][1] = 5;
  points[11][2] = 1;

  points[12][0] = 2;
  points[12][1] = 6;
  points[12][2] = 1;

  points[13][0] = 2;
  points[13][1] = 7;
  points[13][2] = 1;

  points[14][0] = 5;
  points[14][1] = 1;
  points[14][2] = 2;

  points[15][0] = 5;
  points[15][1] = 2;
  points[15][2] = 2;

  points[16][0] = 5;
  points[16][1] = 3;
  points[16][2] = 2;

  points[17][0] = 5;
  points[17][1] = 4;
  points[17][2] = 2;

  points[18][0] = 5;
  points[18][1] = 5;
  points[18][2] = 2;

  points[19][0] = 5;
  points[19][1] = 6;
  points[19][2] = 2;

  // whoa that was 80 lines of initializing

  int knn;
  float x,y;
  cout<<endl<<"How many neighbours should be considered [for better performance donot enter this in multiples of classes] ?"<<endl; // in our case we have 3 cases tall short and avg so donot enter in multiples of 3 
  cin>>knn;
  cout<<endl<<endl<<"Enter the point (x,y) which you want to classify ?"<<endl;
  cin>>x;
  cin>>y;

  for(int i=0;i<20;i++)
    points[i][3] = sqrtf(powf((y - points[i][1]),2) + powf((x - points[i][0]),2));

  // sqrtf and powf are specifically designed for float arithmetic and output huge values
  // you may want to use double everywhere instead of float
  // now sort the distances and then consider the top 'k' neighbours
  for(int i=0;i<20;i++)   // simple bubble sort
  {
    for(int j=0;j<20;j++)
    {
      if(points[j][3] > points[j+1][3]) // sorting on the basis of the 'distance' part
      {
        float p0 = points[j][0];  // all this needs to be swapped
        float p1 = points[j][1];
        float p2 = points[j][2];
        float p3 = points[j][3];

        points[j][0] = points[j+1][0];
        points[j][1] = points[j+1][1];
        points[j][2] = points[j+1][2];
        points[j][3] = points[j+1][3];

        points[j+1][0] = p0;
        points[j+1][1] = p1;
        points[j+1][2] = p2;
        points[j+1][3] = p3;    // quite neatly done
      }
    }
  }

int shortCount = 0;
int averageCount = 0;
int tallCount = 0;

cout<<endl<<"The nearest neighbours are - "<<endl;

for(int i=1;i<=knn;i++)//points 0,0 was coming in the output eventhought we didnt give it as a point for an input 
{
  cout<<"("<<points[i][0]<<","<<points[i][1]<<")"<<endl;
  if(points[i][2] == 0) // short - the 3rd column is the class 
    shortCount++;

  if(points[i][2] == 1) // average
    averageCount++;

  if(points[i][2] == 2) // tall
    tallCount++;
}

// now simply find the majority vote

if((shortCount > averageCount) && (shortCount > tallCount))
  cout<<endl<<"The point ("<<x<<","<<y<<") belongs to the class -> Short"<<endl<<endl;
else if((averageCount > shortCount) && (averageCount > tallCount))
  cout<<endl<<"The point ("<<x<<","<<y<<") belongs to the class -> Average"<<endl<<endl;
else if((tallCount > shortCount) && ( tallCount > averageCount))
  cout<<endl<<"The point ("<<x<<","<<y<<") belongs to the class -> Tall"<<endl<<endl;
else 
  cout<<endl<<"please enter different value for neighbours knn as two parameters have similar count ";

  return 0;
}
