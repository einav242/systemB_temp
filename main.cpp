#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    ariel::Notebook notebook;
    try
    {
        string s;
        cout << "coose the function you want: write/read/erase/show/exit\n";
        cin >> s;
        while (s != "exit")
        {
            if (s == "write")
            {
                int r, c, p;
                string d1;
                Direction d;
                string s1;
                string s2;
                const unsigned int maxcol = 100;
                cout << "please choose number of page\n";
                cin >> p;
                while (p < 0)
                {
                    cout << " only positive number can be a row please choose diffrent numbr\n";
                    cin >> p;
                }
                cout << "please choose number of row\n";
                cin >> r;
                while (r < 0)
                {
                    cout << " only positive number can be a row please choose diffrent numbr\n";
                    cin >> r;
                }
                cout << "please choose number of colum\n";
                cin >> c;
                while (c > maxcol || c < 0)
                {
                    cout << "only positive number less the 100 can be a colum please choose diffrent numbr\n";
                    cin >> c;
                }
                cout << "Horizontal/Vertical\n";
                cin >> d1;
                while (d1 != "Horizontal" && d1 != "Vertical")
                {
                    cout << "try again\n";
                    cin >> d1;
                }
                if (d1 == "Vertical")
                {
                    d = Direction::Vertical;
                }
                else
                {
                    d = Direction::Horizontal;
                }
                cout << "What do you want to write?\n";
                cin >> s1;
                notebook.write(p, r, c, d, s1);
            }
            if (s == "read")
            {
                int r, c, p;
                int data;
                string d1;
                Direction d;
                const unsigned int maxcol = 100;
                cout << "please choose number of page\n";
                cin >> p;
                while (p < 0)
                {
                    cout << " only positive number can be a row please choose diffrent numbr\n";
                    cin >> p;
                }
                cout << "please choose number of row\n";
                cin >> r;
                while (r < 0)
                {
                    cout << " only positive number can be a row please choose diffrent numbr\n";
                    cin >> r;
                }
                cout << "please choose number of colum\n";
                cin >> c;
                while (c > maxcol || c < 0)
                {
                    cout << "only positive number less the 100 can be a colum please choose diffrent numbr\n";
                    cin >> c;
                }
                cout << "Horizontal/Vertical\n";
                cin >> d1;
                while (d1 != "Horizontal" && d1 != "Vertical")
                {
                    cout << "try again\n";
                    cin >> d1;
                }
                if (d1 == "Vertical")
                {
                    d = Direction::Vertical;
                }
                else
                {
                    d = Direction::Horizontal;
                }
                cout << "how many characters would you like to read\n";
                cin >> data;
                while (data < 0)
                {
                    cout << "try again\n";
                    cin >> c;
                }
                cout << notebook.read(p, r, c, d, data);
                cout << '\n';
            }
            if (s == "erase")
            {
                int r, c, p;
                int data;
                string d1;
                Direction d;
                const unsigned int maxcol = 100;
                cout << "please choose number of page\n";
                cin >> p;
                while (p < 0)
                {
                    cout << " only positive number can be a row please choose diffrent numbr\n";
                    cin >> p;
                }
                cout << "please choose number of row\n";
                cin >> r;
                while (r < 0)
                {
                    cout << " only positive number can be a row please choose diffrent numbr\n";
                    cin >> r;
                }
                cout << "please choose number of colum\n";
                cin >> c;
                while (c > maxcol || c < 0)
                {
                    cout << "only positive number less the 100 can be a colum please choose diffrent numbr\n";
                    cin >> c;
                }
                cout << "Horizontal/Vertical\n";
                cin >> d1;
                while (d1 != "Horizontal" && d1 != "Vertical")
                {
                    cout << "try again\n";
                    cin >> d1;
                }
                if (d1 == "Vertical")
                {
                    d = Direction::Vertical;
                }
                else
                {
                    d = Direction::Horizontal;
                }
                cout << "how many characters would you like to erase\n";
                cin >> data;
                while (data < 0)
                {
                    cout << "try again\n";
                    cin >> data;
                }
                notebook.erase(p, r, c, d, data);
            }
            if (s == "show")
            {
                int p;
                cout << "please choose number of page\n";
                cin >> p;
                while (p < 0)
                {
                    cout << " only positive number can be a row please choose diffrent numbr\n";
                    cin >> p;
                }
                notebook.show(p);
            }
            cout << "coose the function you want: write/read/erase/show/exit\n";
            cin >> s;
        }
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
}