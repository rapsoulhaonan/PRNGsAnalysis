#include <iostream>
using namespace std;

class mRND
{
public:
	void seed(unsigned int s) { _seed = s; }

protected:
	mRND() : _seed(0), _a(0), _c(0), _m(2147483648) {}
	int rnd() { return(_seed = (_a * _seed + _c) % _m); }

	int _a, _c;
	unsigned int _m, _seed;
};
class MS_RND : public mRND
{
public:
	MS_RND() { _a = 214013; _c = 2531011; }
	int rnd() { return mRND::rnd() >> 16; }
};
class BSD_RND : public mRND
{
public:
	BSD_RND() { _a = 1103515245; _c = 12345; }
	int rnd() { return mRND::rnd(); }
};
int main(int argc, char* argv[])
{
	BSD_RND bsd_rnd;
	MS_RND ms_rnd;

	cout << "10 random numbers:" << endl ;
	int a[10];
	for (int x = 0; x < 10; x++) {
		a[x] = ms_rnd.rnd();
		cout << a[x] << endl;
	}
	int m, n, j, r;
	int	sum = 0;

	for (j = 0; j < 10; j += 2)
	{
		m = a[j];
		n = a[j + 1];
		do
		{
			r = m%n;
			m = n;
			n = r;
		} while (r != 0);
		if (m == 1)
			sum = sum + 1;
	}

	double Pi, p;
	p = 30.0 / sum;
	Pi = sqrt(p);
	cout << "Estimate value of Pi is: " << Pi << "\n";
	system("pause");
	return 0;
}
