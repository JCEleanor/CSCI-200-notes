#include <random>
#include <iostream>
#include <tuple>

using namespace std;

double getValidDouble(const string prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            return value;
        }
        else
        {
            cout << "Error: Please enter a valid number." << endl;
            // end the loop
            cin.clear();
        }
    }
}

tuple<double, double, double> generateRandomValue()
{
    double minValue = getValidDouble("Enter the minimum value: ");
    double maxValue = getValidDouble("Enter the maximum value: ");

    // get num
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> randomValue(minValue, maxValue);

    const double randomValueOutput = randomValue(mt);

    cout << "A random value is: " << randomValueOutput << endl;

    return {randomValueOutput, minValue, maxValue};
}

void generateQuartile(double randomValueOutput, double minValue, double maxValue){
    double totalRange = maxValue - minValue;
    double quater = totalRange / 4;
    string quartileOutput;

    if (randomValueOutput >= minValue && randomValueOutput < (minValue + quater))
    {
        quartileOutput = "first";
    }
    else if (randomValueOutput >= (minValue + quater) && randomValueOutput < (minValue + quater * 2))
    {
        quartileOutput = "second";
    }
    else if (randomValueOutput >= (minValue + quater * 2) && randomValueOutput < (minValue + quater * 3))
    {
        quartileOutput = "third";
    }
    else
    {
        quartileOutput = "fourth";
    }

    cout << "This is in the " << quartileOutput << " quartile" << endl;
}

int main()
{
    bool isGenerateRandomValue = true;
    while (isGenerateRandomValue)
    {
        const auto [randomValueOutput, minValue, maxValue] = generateRandomValue();

        generateQuartile(randomValueOutput, minValue, maxValue);
        cout << "Do you want another random value? (Y/N) ";
        char answer;
        cin >> answer;
        if (answer == 'N')
        {
            isGenerateRandomValue = false;
        }

    }
    return 0;
}