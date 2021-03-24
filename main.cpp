#include "Time.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int hour{};
    int minute{};
    int second{};
    int format{};
    int num{};
    int menu{};
    
    bool valid1{};
    bool valid2{};
    
    Time time{};

    cin >> time;
    cout << time;

    do
    {
        cout << "Choose the clock format below:" << endl;
        cout << "1. 24-hour" << endl;
        cout << "2. 12-hour" << endl;
        cout << "Choice: ";
        cin >> format;
        cout << endl;

        if (format != 1 && format != 2)
        {
            cout << "INVALID INPUT! Please select 1 or 2." << endl;
        }
        
        else
        {
            //cout << toString (time, format) << endl;
                    
            cout << endl;
            cout << "OPERATOR OVERLOADING MENU" << endl;
            cout << setfill('-') << setw(25) << "-" << endl;
            cout << setfill(' ');
                    
            cout << "1. Operator+" << setw(20) << " " << right;
            cout << "2. Operator-" << endl;
            cout << "3. Operator++ (Prefix)" << setw(10) << " " << right;
            cout << "4. Operator++ (Postfix)" << endl;
            cout << "5. Operator-- (Prefix)" << setw(10) << " " << right;
            cout << "6. Operator-- (Postfix)" << endl;
            cout << "7. Operator<" << setw(20) << " " << right;
            cout << "8. Operator>" << endl;
            cout << "9. Operator<=" << setw(19) << " " << right;
            cout << "10. Operator>=" << endl;
            cout << "11. Operator==" << setw(18) << " " << right;
            cout << "12. Operator!=" << endl;
            cout << "13. Operator<<" << setw(18) << " " << right;
            cout << "14. Operator>>" << endl;
                    
            cout << endl;
            cout << "Choice: ";
            cin >> menu;
            cout << endl;
                    
            switch (menu)
            {
                case 1:
                {
                    cout << "Enter time increment value: ";
                    cin >> num;
                    Time t1 = time + num;
                    cout << t1 << endl;
                    break;
                }
                        
                case 2:
                {
                    cout << "Enter time decrement value: ";
                    cin >> num;
                    Time t1 = time - num;
                    cout << t1 << endl;
                    break;
                }
                        
                case 3:
                {
                    ++time;
                    cout << time << endl;
                    break;
                }

                case 4:
                {
                    time++;
                    cout << time << endl;
                    break;
                }
                        
                case 5:
                {
                    --time;
                    cout << time << endl;
                    break;
                }
                        
                case 6:
                {
                    time--;
                    cout << time << endl;
                    break;
                }
                        
                case 7:
                {
                    Time time2{};
                    cin >> time2;
                            
                    cout << "Time 1 = " << time << endl;
                    cout << "Time 2 = " << time2 << endl;
                    cout << "Time 1 < Time 2 is ";
                            
                    if (time < time2)
                    {
                        cout << "true" << endl;
                    }
                                    
                    else
                    {
                        cout << "false" << endl;
                    }
                            
                    break;
                }
                        
                case 8:
                {
                    Time time2{};
                    cin >> time2;
                            
                    cout << "Time 1 = " << time << endl;
                    cout << "Time 2 = " << time2 << endl;
                    cout << "Time 1 > Time 2 is ";
                        
                    if (time > time2)
                    {
                        cout << "true" << endl;
                    }
                                    
                    else
                    {
                        cout << "false" << endl;
                    }
                            
                    break;
                }
                        
                case 9:
                {
                    Time time2{};
                    cin >> time2;
                            
                    cout << "Time 1 = " << time << endl;
                    cout << "Time 2 = " << time2 << endl;
                    cout << "Time 1 <= Time 2 is ";
                        
                    if (time <= time2)
                    {
                        cout << "true" << endl;
                    }
                                    
                    else
                    {
                        cout << "false" << endl;
                    }
                            
                    break;
                } 
                
                case 10:
                {
                    Time time2{};
                    cin >> time2;
                            
                    cout << "Time 1 = " << time << endl;
                    cout << "Time 2 = " << time2 << endl;
                    cout << "Time 1 >= Time 2 is ";
                        
                    if (time >= time2)
                    {
                        cout << "true" << endl;
                    }
                                    
                    else
                    {
                        cout << "false" << endl;
                    }
                            
                    break;
                }

                case 11:
                {
                    Time time2{};
                    cin >> time2;
                            
                    cout << "Time 1 = " << time << endl;
                    cout << "Time 2 = " << time2 << endl;
                    cout << "Time 1 == Time 2 is ";
                        
                    if (time == time2)
                    {
                        cout << "true" << endl;
                    }
                                    
                    else
                    {
                        cout << "false" << endl;
                    }
                            
                    break;
                }
                        
                case 12:
                {
                    Time time2{};
                    cin >> time2;
                            
                    cout << "Time 1 = " << time << endl;
                    cout << "Time 2 = " << time2 << endl;
                    cout << "Time 1 != Time 2 is ";
                        
                    if (time != time2)
                    {
                        cout << "true" << endl;
                    }
                                    
                    else
                    {
                        cout << "false" << endl;
                    }
                            
                    break;
                }
                        
                case 13:
                {
                    cout << time << endl;
                    break;
                }
                        
                case 14:
                {
                    cin >> time;
                    cout << time;
                    break;
                }
                        
                default:
                {
                    cout << "INVALID INPUT!" << endl;
                }
            }
        }
    } while (format != 1 && format != 2);
    
    return 0;
}