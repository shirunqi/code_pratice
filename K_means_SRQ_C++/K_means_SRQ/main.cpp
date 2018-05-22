//
//  main.cpp
//  K_means_SRQ
//
//  Created by 石润奇 on 2018/3/22.
//  Copyright © 2018年 石润奇. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

const int NUMBER_OF_ROW = 40;
const int k = 4;
bool If_Equal(const double A[NUMBER_OF_ROW][2], const double B[NUMBER_OF_ROW][2]);

int main()
{
    ifstream input("data.txt");
    //    ifstream input("/Users/mac/Documents/SRQ/practice/C++/K_means_SRQ/K_means_SRQ/data.txt"); // 绝对路径OK
    
    // Read data
    double data[NUMBER_OF_ROW][2];
    for (int i = 0; i < NUMBER_OF_ROW; i++)
    {
        input >> data[i][0] >> data[i][1];
    }
    input.close();

    // Randomly select k centers
    double CenterPoints[k][2];
     srand(time(0));
     for (int i = 0; i < k; i++)
     {
     int j = 0;
     j = rand() % NUMBER_OF_ROW + 1;
     CenterPoints[i][0] = data[j][0];
     CenterPoints[i][1] = data[j][1];
     }
    
    double arrayA[NUMBER_OF_ROW][2];
    double arrayB[NUMBER_OF_ROW][2];
    double arrayC[NUMBER_OF_ROW][2];
    double arrayD[NUMBER_OF_ROW][2];
    double arrayA1[NUMBER_OF_ROW][2];
    double arrayB1[NUMBER_OF_ROW][2];
    double arrayC1[NUMBER_OF_ROW][2];
    double arrayD1[NUMBER_OF_ROW][2];
    for (int i = 0; i < NUMBER_OF_ROW; i++)
    {
        arrayA[i][0] = 0;
        arrayA[i][1] = 0;
        arrayB[i][0] = 0;
        arrayB[i][1] = 0;
        arrayC[i][0] = 0;
        arrayC[i][1] = 0;
        arrayD[i][0] = 0;
        arrayD[i][1] = 0;
        arrayA1[i][0] = 1;
        arrayA1[i][1] = 1;
        arrayB1[i][0] = 1;
        arrayB1[i][1] = 1;
        arrayC1[i][0] = 1;
        arrayC1[i][1] = 1;
        arrayD1[i][0] = 1;
        arrayD1[i][1] = 1;
    }
    
    double distant[k];
    for (int i = 0; i < k; i++)
    {
        distant[i] = 0.0;
    }
    double mean[k][2];
    double sum[k][2];
    
    int n = 0;
    // Calculating the distance between the center and each data point
    while (!(If_Equal(arrayA, arrayA1) && If_Equal(arrayB, arrayB1) && If_Equal(arrayC, arrayC1) && If_Equal(arrayD, arrayD1)))
    {
        for (int i = 0; i < NUMBER_OF_ROW; i++)
        {
            arrayA1[i][0] = arrayA[i][0];
            arrayA1[i][1] = arrayA[i][1];
            arrayB1[i][0] = arrayB[i][0];
            arrayB1[i][1] = arrayB[i][1];
            arrayC1[i][0] = arrayC[i][0];
            arrayC1[i][1] = arrayC[i][1];
            arrayD1[i][0] = arrayD[i][0];
            arrayD1[i][1] = arrayD[i][1];
        }
        for (int i = 0; i < NUMBER_OF_ROW; i++)
        {
            arrayA[i][0] = 0;
            arrayA[i][1] = 0;
            arrayB[i][0] = 0;
            arrayB[i][1] = 0;
            arrayC[i][0] = 0;
            arrayC[i][1] = 0;
            arrayD[i][0] = 0;
            arrayD[i][1] = 0;
            
        }
       
        for (int i = 0; i < NUMBER_OF_ROW; i++)
        {
            for (int j = 0; j < k; j++)
            {
                distant[j] = sqrt((data[i][0] - CenterPoints[j][0]) * (data[i][0] - CenterPoints[j][0]) + (data[i][1] - CenterPoints[j][1]) * (data[i][1] - CenterPoints[j][1]));
            }
            
            // Finding the maximum value of an array element and its subscript/index
            double min = distant[0];
            int indexOfMin = 0;
            
            for (int m = 1; m < k; m++)
            {
                if (distant[m] < min)
                {
                    min = distant[m];
                    indexOfMin = m;
                }
            }
            switch (indexOfMin)
            {
                case 0:
                    arrayA[i][0] = data[i][0];
                    arrayA[i][1] = data[i][1];
                    break;
                case 1:
                    arrayB[i][0] = data[i][0];
                    arrayB[i][1] = data[i][1];
                    break;
                case 2:
                    arrayC[i][0] = data[i][0];
                    arrayC[i][1] = data[i][1];
                    break;
                case 3:
                    arrayD[i][0] = data[i][0];
                    arrayD[i][1] = data[i][1];
                    break;
            }
        }
        
        // Calculate the mean
        for (int i = 0; i < k; i++)
        {
            mean[i][0] = 0;
            mean[i][1] = 0;
            sum[i][0] = 0;
            sum[i][1] = 0;
        }
        for (int j = 0; j < NUMBER_OF_ROW; j++)
        {
            sum[0][0] += arrayA[j][0];
            sum[0][1] += arrayA[j][1];
        }
        
        for (int j = 0; j < NUMBER_OF_ROW; j++)
        {
            sum[1][0] += arrayB[j][0];
            sum[1][1] += arrayB[j][1];
        }
        
        for (int j = 0; j < NUMBER_OF_ROW; j++)
        {
            sum[2][0] += arrayC[j][0];
            sum[2][1] += arrayC[j][1];
        }
        
        for (int j = 0; j < NUMBER_OF_ROW; j++)
        {
            sum[3][0] += arrayD[j][0];
            sum[3][1] += arrayD[j][1];
        }
        
        double n1 = 0.0;
        double n2 = 0.0;
        double n3 = 0.0;
        double n4 = 0.0;
        
        for (int i = 0; i < NUMBER_OF_ROW; i++)
        {
            if ((arrayA[i][0] != 0) || (arrayA[i][1] != 0))
            {
                n1++;
            }
            if ((arrayB[i][0] != 0) || (arrayB[i][1] != 0))
            {
                n2++;
            }
            if ((arrayC[i][0] != 0) || (arrayC[i][1] != 0))
            {
                n3++;
            }
            if ((arrayD[i][0] != 0) || (arrayD[i][1] != 0))
            {
                n4++;
            }
            
        }
        
        mean[0][0] = sum[0][0] / n1;
        mean[0][1] = sum[0][1] / n1;
        mean[1][0] = sum[1][0] / n2;
        mean[1][1] = sum[1][1] / n2;
        mean[2][0] = sum[2][0] / n3;
        mean[2][1] = sum[2][1] / n3;
        mean[3][0] = sum[3][0] / n4;
        mean[3][1] = sum[3][1] / n4;
        
        // Update Cluster Center
        for (int i = 0; i < k; i++)
        {
            CenterPoints[i][0] = mean[i][0];
            CenterPoints[i][1] = mean[i][1];
            
            cout << "第" << n + 1 << "次迭代的第" << i + 1 << "个中心坐标为：" << CenterPoints[i][0] << setw(10) << CenterPoints[i][1] << endl;
        }
        n++;
    }
    
    // save data
    ofstream output1;
    ofstream output2;
    ofstream output3;
    ofstream output4;
    ofstream outputcenter;
    
    output1.open("data1.txt");
    output2.open("data2.txt");
    output3.open("data3.txt");
    output4.open("data4.txt");
    outputcenter.open("data5.txt");
    
    for (int i = 0; i < NUMBER_OF_ROW; i++)
    {
        if ((arrayA[i][0] != 0) && (arrayA[i][0] != 0))
        {
            output1 << arrayA[i][0] << setw(10) << arrayA[i][1] << endl;
        }
        if ((arrayB[i][0] != 0) && (arrayB[i][0] != 0))
        {
            output2 << arrayB[i][0] << setw(10) << arrayB[i][1] << endl;
        }
        if ((arrayC[i][0] != 0) && (arrayC[i][0] != 0))
        {
            output3 << arrayC[i][0] << setw(10) << arrayC[i][1] << endl;
        }
        if ((arrayD[i][0] != 0) && (arrayD[i][0] != 0))
        {
            output4 << arrayD[i][0] << setw(10) << arrayD[i][1] << endl;
        }
    }
    for (int i = 0; i < k; i++)
    {
        outputcenter << CenterPoints[i][0] << setw(10) << CenterPoints[i][1] << endl;
    }
    
    output1.close();
    output2.close();
    output3.close();
    output4.close();
    cout << "迭代次数：" << n << "次" << endl;
    
    return 0;
}

// Determine whether the two results are equal before and after
bool If_Equal(const double A[NUMBER_OF_ROW][2], const double B[NUMBER_OF_ROW][2])
{
    bool isEqual[NUMBER_OF_ROW];
    for (int i = 0; i < NUMBER_OF_ROW; i++)
    {
        isEqual[i] = false;
    }
    
    for (int i = 0; i < NUMBER_OF_ROW; i++)
    {
        if (A[i][0] == B[i][0] && A[i][1] == B[i][1])
        {
            isEqual[i] = true;
        }
    }
    
    bool allEqual = true;
    for (int i = 0; i < NUMBER_OF_ROW; i++)
    {
        if (!isEqual[i])
        {
            allEqual = false;
            break;
        }
    }
    
    if (allEqual)
    {
        return true;
    }
    else
    {
        return false;
    }
}

