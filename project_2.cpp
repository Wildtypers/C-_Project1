#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

//load dva function for calculated required power defense
void load_dva(float& loadedPowerDefense, float matrixPowerRequired)
{
    if (loadedPowerDefense <= matrixPowerRequired)
    {
        loadedPowerDefense = matrixPowerRequired;
    }
}

//load dva function for calculating required missiles
void load_dva(int& numMissiles, float missilePowerRequired)
{
    int missilesRequired;
    missilesRequired = ceil(missilePowerRequired/30);
    if (missilesRequired > numMissiles){
        numMissiles = missilesRequired;
    }
}

//template function to determine power of missiles
template <typename T>
T single_missle_power(T power)
{
    if (power <= 15)
    {
        return power * 3;
    }
    else{
        return power * 5;
    }
}

//determining the total damage from the bots
float matrix_power(int botPower[], int numBots, float bossPower)
{
    float totalDamage = 0;
    for (int i = 0; i < numBots; i++)
    {
        totalDamage += botPower[i];
    }
    totalDamage += bossPower;
    return totalDamage;
}

int main(){
    //Loading the file
    ifstream battleData;
    battleData.open("combat.txt");
    
    //checking if file exists
    if (battleData.fail())
    {
        cout << "Fail to open File." << endl;
        return 0;
    }

    //loading bot numbers
    int botNum;
    battleData >> botNum;

    //loading bot damage
    int damage[botNum];
    int tempDamage;
    for (int i = 0; i < botNum; i++)
    {
        battleData >> tempDamage;
        damage[i] = tempDamage;
    }

    //loading final boss damage
    float finalBossDamage;
    battleData >> finalBossDamage;

    //loading default number of missiles
    int missleNum;
    battleData >> missleNum;

    //loading defense matrix
    float defenseMatrix;
    battleData >> defenseMatrix;

    //closing input file
    battleData.close();
    
    //getting matrix power required
    float matrixPowerRequired;
    matrixPowerRequired = matrix_power(damage, botNum, finalBossDamage); 

    //getting the misslePowerRequired
    float missilePowerRequired = 0;
    for (int i = 0; i < botNum; i++){
        int tempBattleNum;
        tempBattleNum = damage[i];
        missilePowerRequired += single_missle_power(tempBattleNum);
    }
    missilePowerRequired += single_missle_power(finalBossDamage);

    //calling function to determine defense Matrix
    load_dva(defenseMatrix, matrixPowerRequired);

    //calling function to determine number of missles
    load_dva(missleNum, missilePowerRequired);

    //opening output file
    ofstream report;
    report.open("report.txt");

    //checking if output file opens
    if (report.fail()){
        cout << "failed to open file" <<endl;
        return 0;
    }

    //adding data to the reports
    report << "D.Va's Combat Report" << endl;
    report << "Combat with " << botNum << " enemy bots and one enemy boss with power " << finalBossDamage << "." << endl;
    report << "Loaded mech with " << missleNum << " micro missiles and the defense matrix with power " << defenseMatrix << "." << endl;
    report << "Ready for combat!" << endl;

    //closing the report
    report.close();
    
    return 0;
}