#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

#define ll long long
#define ull unsigned long long
#define ndl "\n"
#define Z size()

//  inputcrap
#define in1(a) cin >> a;
#define in2(a, b) cin >> a >> b;
#define in3(a, b, c) cin >> a >> b >> c;
#define in4(a, b, c, d) cin >> a >> b >> c >> d;
#define in5(a, b, c, d, e) cin >> a >> b >> c >> d >> e;

// Loopyverse
#define arr_fill(arr, n) ff(i, 0, n) cin >> arr[i];
#define arr_sprint(arr, n) ff(i, 0, n) cout << arr[i];
#define arr_bprint(arr, n) ff(i, 0, n) cout << arr[i] << " ";
#define arr_nprint(arr, n) ff(i, 0, n) cout << arr[i] << ndl;
#define w(t) while (t--)
#define wm(t) while (t)
#define ff(i, a, b) for (ll i = a; i < b; i++)
#define ffe(i, a, b) for (ll i = a; i <= b; i++)
#define fb(i, a, b) for (ll i = a; i > b; i--)
#define fbe(i, a, b) for (ll i = a; i >= b; i--)

#define solve() work()
#define test_case() \
    int t = 1;      \
    cin >> t;       \
    w(t) solve();

/* ------------- code starts here --------- */
bool  temp=0;
bool gameOver = 0;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score;
int tailx[100], taily[100];
int ntail=100;
enum eDirection { STOP = 0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = (rand() % width) + 1;
    fruity = (rand() % height) + 1;
    int score = 0;
}

void draw()
{
    system("cls");
    ffe(i, 1, width + 2) // for top line
        cout << "#";
    cout << ndl;

    ff(i, 0, height)
    {
        ff(j, 0, width + 2)
        {
            if (j == 0 or j == width + 1)
                cout << "#"; // LR borders
            else if (i == y and j == x)
                cout << "O"; // head
            else if (i == fruity and j == fruitx)
                cout << "F";
            else
            {
                bool print= 0;
                ff(k,0,ntail)
                {
                    if (tailx[k] == j and taily[k] == i)
                        cout << "o", print = true;
                }
                if (!print)
                    cout << " ";
            }
        }
        cout << ndl;
    }

    ffe(i, 1, width + 2) // for bottom line
        cout << "#";
    cout << endl;

    cout << "Score = " << score ;
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'g':   // press to quit the game
            gameOver = 1;
            break;
        default:
            break;
        }
    }
}

void logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = x;
    taily[0] = y;
    ff(i,1,ntail)
    {   // following tail
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    // dir = STOP;
    
//     for dimensional wall
    if (x > width)
        x = x % width;
    if (!x)
        x = width;
    if (y == height)
        y = y % height;
    if (y < 0)
        y = height - 1;

    //normal wall
//  if (x > width)      goto over;
//  if (!x)             goto over;
//  if (y == height)    goto over;
//  if (y < 0)          goto over;
//  if (temp==1){
//      over:
//          gameOver = true;
//  }

    if (fruitx == x and fruity == y)
    {   // eating fruit | new fruit | increasing tail 
        score += 10;
        while (x == fruitx and y == fruity)
        {
            fruitx = rand() % width;
            fruity = rand() % height;
        }
        ntail++;
    }
}
int main()
{
    setup();
    wm(!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(100);
    }
    cout << "Score = " << score ;

}

/* Snake Game
    Dimensional wall
    can't kill yourself 
    score
    tail length
    speed control
    
*/
