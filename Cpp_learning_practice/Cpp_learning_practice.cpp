// Cpp_learning_practice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>		//setw()
//定义pi
#include <math.h>
#define pi acos(-1)  //3.14159
#define MAX 30

using namespace std;

//生成随机数
/*
#include <stdlib>
rand()
rand() % 100
产生[m, n]范围内的随机数num，可用：
int num = rand() % (n - m + 1) + m;

#include <time>
产生10~30的随机整数：
srand(time(0));       //真正的随机数
int a = rand() % (21) + 10
srand(time(0));

int i, min, max, sum = 0;
float average;
int a[10];
cout << "随机数组如下：" << endl;
a[0] = rand() % 71 + 30;
min = a[0];
max = a[0];
cout << a[0] << " ";
sum = sum + a[0];
for (i = 1; i < 10; i++)
{
	a[i] = rand() % 71 + 30;
	sum = sum + a[i];
	cout << a[i] << " ";
	if (a[i] < min)
	{
		min = a[i];
	}
	if (a[i] > max)
	{
		max = a[i];
	}
}
average = sum / 10.0;
cout << "\n最大值：" << max << endl;
cout << "最小值：" << min << endl;
cout << "平均值：" << average << endl;
*/

//排序(冒泡)
/*
int i, j, t, a[20];
srand(time(0));
cout << "原数组：" << endl;
for (i = 0; i < 20; i++)
{
	a[i] = rand() % 101;
	cout << a[i] << " ";
}
for (i = 0; i < 20; i++)
{
	for (j = i + 1; j < 20; j++)
	{
		if (a[j] > a[i])
		{
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	}
}
cout << "\n从大到小排序后：" << endl;
for (i = 0; i < 20; i++)
{
	cout << a[i] << " ";
}
*/

//数组元素循环移位
/*
#define MAX 10
int i, j, m, a[MAX], b[MAX];
srand(time(0));
cout << "原数组：" << endl;
for (i = 0; i < MAX; i++)
{
	a[i] = rand() % 101;
	cout << a[i] << " ";
}

cout << "\n请输入移位数 m =";
cin >> m;
if (m >= MAX)
{
	m = m % MAX;
}
for (i = 0; i < MAX; i++)
{
	j = i + m;
	if (j >= MAX)
	{
		j = j % MAX;
	}
	b[j] = a[i];
}
cout << "移动 " << m << " 位后数组：" << endl;
for (i = 0; i < MAX; i++)
{
	a[i] = b[i];
	cout << a[i] << " ";
}
*/

//二分法!!!
int Binary_Search_def(int str[], int low, int high, int key)
{
	if (low > high)
	{
		return -1;
	}
	int mid = (low + high) / 2;
	if (key == str[mid])
	{
		return mid;
	}
	else
	{
		if (key < str[mid])
		{
			return Binary_Search_def(str, low, mid - 1, key);
		}

		else
		{
			return Binary_Search_def(str, mid + 1, high, key);
		}
	}
}

//杨辉三角
void YangHui(int n)
{
	const int max = 10;
	int a[max][max];
	int i, j;
	for (i = 0; i < n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (i = 2; i < n; i++)
	{
		for (j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << setw((n - i) * 1) << ' ';	//输出格式！ ？？？
		for (j = 0; j <= i; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
};

//一个数组实现字符串逆序存放
void InvOrder(char a[])
{
	int n, i;
	char t;
	n = strlen(a);
	for (i = 0; i < n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
	a[n] = '\0';
	//cout << "逆序处理之后 " << a << endl;
};

//字符串大小写转换
void a2A_A2a(char str[])
{
	char* p = str;
	while (*p != '\0')
	{
		if (*p >= 97 && *p <= 122)
		{
			*p = *p - 32;
		}
		else
		{
			if (*p >= 65 && *p <= 90)
			{
				*p = *p + 32;
			}
		}
		p++;
	}
};

//字符串复制——字符串s中从第n个字符开始的内容复制到字符串t中
void strcpy_def(char target[], char str[], int n)
{
	int i = 0;
	char* p = str;
	if (n < 0 || n >= strlen(str))
	{
		cout << "n 不合法！" << endl;
		return;
	}
	else
	{
		p = p + n;
		while (*p != '\0')
		{
			target[i] = *p;
			i++;
			p++;
		}
		target[i] = '\0';
	}
}

//素数  输出孪生素数
bool isprime(int m)
{
	int i;
	for (i = 2; i <= sqrt(m); i++)
	{
		if (m % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void OutputTwinPrime()
{
	int i = 0, n = 0;
	int a[100];
	//素数存放进数组a
	for (i = 3; i < 200; i++)
	{
		if (isprime(i) == 1)
		{
			//cout << i << ' ';
			a[n] = i;
			n++;
		}
	}
	n = 0;
	//输出孪生素数
	for (i = 0; i < 100; i++)
	{
		if (a[i + 1] - a[i] == 2 && n < 10)
		{
			cout << '<' << a[i] << ',' << a[i + 1] << '>' << endl;
			n++;
		}
	}
}

//回文字符串
int huiwen(char s[])
{
	int n, i;
	n = strlen(s);			//长度包括'\0' —— 实际长度+1
	for (i = 0; i < n / 2; )
	{
		if (s[i] == s[n - i - 2])	//长度变化！！！
		{
			i++;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//学生成绩
//参数传递的方式，注意区分！！！
/*
	int a = 0;
	int& x = a;
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;

	1.int &x一般只用于函数的参数中， 而int y不止用在函数参数中。
	2.int &x做参数时，传递变量是该实参的引用类型，函数执行过程中
	  可以改变实参的值，而int y传递的是实参的拷贝，函数执行后不改变实参的值。
*/
int fun1(int s[], int n, int* p)
{
	int i, j, t;
	//冒泡排序，从大到小
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[j] > s[i])
			{
				t = s[j];
				s[j] = s[i];
				s[i] = t;
			}
		}
	}
	cout << "\n从大到小排序后：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	//不及格人数
	i = 0;
	while (s[i] >= 60)
	{
		i++;
	}
	*p = n - i;
	//优秀人数
	i = 0;
	while (s[i] >= 90)
	{
		i++;
	}
	return i;
}

void fun2(int s[], int n, int& x, int& y)
{
	int i, j, t;
	//冒泡排序，从大到小
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[j] > s[i])
			{
				t = s[j];
				s[j] = s[i];
				s[i] = t;
			}
		}
	}
	cout << "\n从大到小排序后：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << s[i] << " ";
	}
	//不及格人数
	i = 0;
	while (s[i] >= 60)
	{
		i++;
	}
	x = n - i;
	//优秀人数
	i = 0;
	while (s[i] >= 90)
	{
		i++;
	}
	y = i;
}

//统计字符串中各个字母（不区分大、小写）出现的频率
void freq(char s[], int p[], char& chmax, int& max)
{
	int i = 0;
	int j;
	char letter;
	int index_max = 0;
	int len = strlen(s);
	while (s[i] != '\0')
	{
		if (s[i] >= 97 && s[i] <= 122)
		{
			j = s[i] - 97;
			p[j] = p[j] + 1;
		}
		else
		{
			if (s[i] >= 65 && s[i] <= 90)
			{
				j = s[i] - 65;
				p[j] = p[j] + 1;
			}
		}
		i++;
	}
	for (i = 0; i < MAX; i++)
	{
		if (p[i] != 0)
		{
			if (p[i] > p[index_max])
			{
				index_max = i;
			}
			letter = i + 97;
			cout << letter << "------" << p[i] << endl;
		}
	}
	max = p[index_max];
	chmax = index_max + 97;
	cout << "出现频率最高的字母:" << chmax << "------" << max << endl;
}

//递归函数，求长度为n的数组的累加和
int sum(int a[], int n)
{
	int sum_seg = 0;

	if (n > 1)
		sum_seg = a[n - 1] + sum(a, n - 1);
	if (n == 1)
	{
		return a[0];
	}
	else
	{
		return sum_seg;
	}
}

//将字符串s中最大字符的地址返回
char* get_max(char s[])
{
	int i = 0;
	char* p = s;
	char* max = s;
	while (*p != '\0')
	{
		if (*p > *max)
		{
			max = p;
		}
		p++;
	}
	return max;
}

//结构体
//max函数返回值为分数最高的学生的信息
struct student
{
	char* num;
	int score;
}AllStudents[MAX];

student* max1()		//返回地址
{
	int nMax = 0;
	int nMaxScore = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (AllStudents[i].score > nMaxScore)
		{
			nMax = i;
			nMaxScore = AllStudents[i].score;
		}
	}
	return &AllStudents[nMax];
}
student max2()		//返回结构体
{
	student maxStudent;
	maxStudent.num = (char*)malloc(sizeof(char));
	maxStudent.num = 0;
	maxStudent.score = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (AllStudents[i].score > maxStudent.score)
		{
			maxStudent.num = AllStudents[i].num;
			maxStudent.score = AllStudents[i].score;
		}
	}
	return maxStudent;
}

//定义一个日期结构变量，计算某日期是本年度的第几天
struct date
{
	int mouth;
	int day;
};
int date_sum(date p)
{
	int i = 0, sum = 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (i < p.mouth - 1)
	{
		sum = sum + days[i];
		i++;
	}
	sum = sum + p.day;
	return sum;
}

//链表
//删除链表中第n个结点
struct staff
{
	char num[6];      //职工工号
	char name[20];    //职工姓名
	double wage;      //职工工资
	staff* next;
};

struct staff* deln(struct staff* head, int n)
{
	struct staff* p, * q = NULL;
	p = head;
	if (n == 0)
	{
		head = p->next;
		delete p;
	}
	else
	{
		while (p != NULL && n != 0)		//找删除结点位置
		{
			q = p;
			p = p->next;
			n--;
		}
		if (n == 0)
		{
			if (p != NULL)			//中间结点
			{
				q->next = p->next;
				delete p;
			}
			else
			{
				cout << "超出链表长度" << endl;
			}
		}
		else
		{
			cout << "超出链表长度" << endl;
		}
	}
	return head;
}

//逆序存储字符串至链表
char str[MAX];
struct abc
{
	char s;
	abc* next;
};
struct abc* create_list()
{
	int i = 0, n;
	n = sizeof(str) / sizeof(char);
	struct abc* head = NULL;
	struct abc* tail = NULL, * newnode = NULL;
	while (str[i] != '\0')
	{
		newnode = new abc;
		//newnode = (struct node*)malloc(sizeof(node));
		newnode->s = str[i];
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			tail->next = newnode;
		}
		tail = newnode;
		i++;
	}
	tail->next = NULL;
	return head;
};
int main()
{
	/*
	int i, x, a[MAX];
	cout << "请从大到小输入" << MAX << "个数" << endl;
	for (i = 0; i < MAX; i++)
	{
		cin >> a[i];
	}
	cout << "请输入要查找的数 x = " << endl;
	cin >> x;
	*/

	//二分法
	/*
	int i, j, t;
	int middle;
	int key;
	int a[MAX];
	srand(time(0));
	cout << "原数组：" << endl;
	for (i = 0; i < MAX; i++)
	{
		a[i] = rand() % 101;
		cout << a[i] << " ";
	}
	for (i = 0; i < MAX; i++)
	{
		for (j = i + 1; j < MAX; j++)
		{
			if (a[j] < a[i])
			{
				t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
	cout << "\n从小到大排序后：" << endl;
	for (i = 0; i < MAX; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n请输入要查找的key = ";
	cin >> key;

	middle = Binary_Search_def(a, 0, MAX - 1, key);
	if (middle == -1)
	{
		cout << "未找到" << key << endl;
	}
	else
	{
		cout << "a[" << middle << "] = " << key << endl;
	}
	*/

	//杨辉三角
	//YangHui(6);

	//一个数组实现字符串逆序存放
	/*
	int i = 0;
	char a[MAX];
	cout << "请输入需要处理的字符串 ";
	//cin >> a;							//处理不了空格！！！！！！
	fgets(a, MAX, stdin);
	InvOrder(a);
	*/

	//字符串大小写转换
	/*
	char str[MAX];
	cout << "请输入要处理的字符串  = ";
	//cin >> a;							//处理不了空格！！！！！！
	fgets(str, MAX, stdin);
	a2A_A2a(str);
	cout << "处理后的字符串  = ";
	cout << str;
	*/

	//字符串复制——字符串s中从第n个字符开始的内容复制到字符串t中
	/*
	char str[MAX];
	char target[MAX];
	int n;
	cout << "请输入要处理的字符串  = ";
	fgets(str, MAX, stdin);
	cout << "从第几位开始复制 n = ";
	cin >> n;
	strcpy_def(target, str, n);
	cout << target << endl;
	*/

	//产生随机数并交换最大和最小的两个数
	/*
	srand(time(0));       //真正的随机数
	int i, t;
	int a[10];
	int* p = a;
	int* min = a;
	int* q = a;
	int* max = a;
	cout << "随机数组如下：" << endl;
	for (i = 0; i < 10; i++)
	{
		a[i] = rand() % 101;
		cout << a[i] << ' ';
	}

	for (; p < a + 10; p++)		//条件
	{
		if (*p < *min)
		{
			min = p;			//地址
		}
	}
	for (; q < a + 10; q++)
	{
		if (*q > *max)
		{
			max = q;
		}
	}
	t = *min;
	*min = *max;
	*max = t;
	cout << endl;
	for (i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
	*/

	//素数  输出孪生素数
	//OutputTwinPrime();

	//回文字符串
	/*
	char str[MAX];
	cout << "请输入要处理的字符串  = ";
	fgets(str, MAX, stdin);
	if (huiwen(str) == 1)
	{
		cout << "是回文字符串" << endl;
	}
	else
	{
		cout << "不是回文字符串" << endl;
	}
	*/

	//学生成绩
	/*
	int i, n;
	int x = 0;
	int y = 0;
	cout << "请输入学生人数 n = ";
	cin >> n;
	int s[MAX];
	//随机生成n个学生的成绩
	srand(time(0));
	cout << n << " 位学生的成绩如下：" << endl;
	for (i = 0; i < n; i++)
	{
		s[i] = rand() % 101;
		cout << s[i] << " ";
	}
	//fun1
	cout << "\n优秀的人数 = " << fun1(s, n, &x) << endl;		//&a!!!
	cout << "不及格的人数 = ";
	printf("%d", x);
	//fun2
	fun2(s, n, x, y);
	cout << "\n优秀的人数 = " << y << endl;
	cout << "不及格的人数 = " << x << endl;
	*/

	//统计字符串中各个字母（不区分大、小写）出现的频率
	/*
	char str[MAX];
	int p[MAX] = { 0 };
	char chmax;
	int max = 0;
	cout << "请输入待处理的字符串：";
	fgets(str, MAX, stdin);
	freq(str, p, chmax, max);
	*/

	//递归函数，求长度为n的数组的累加和
	/*
	int i, sum_all;
	int a[MAX];
	srand(time(0));
	cout << "随机生成数组如下：" << endl;
	for (i = 0; i < MAX; i++)
	{
		a[i] = rand() % 90 + 10;
		cout << a[i] << " ";
	}
	sum_all = sum(a, MAX);
	cout << "\n数组元素和为：" << sum_all << endl;
	*/

	//将字符串s中最大字符的地址返回
	/*
	char str[MAX];
	char* max = NULL;
	cout << "请输入要处理的字符串  = ";
	fgets(str, MAX, stdin);
	max = get_max(str);
	while (*max != '\0')
	{
		if (*max >= 97 && *max <= 122)
		{
			*max = *max - 32;
		}
		max++;
	}
	cout << "处理后的字符串  = ";
	cout << str;
	*/

	//max函数返回值为分数最高的学生的信息
	/*
	int N;
	cout << "输入学生的数量：";
	cin >> N;
	cout << "输入学生的学号和成绩：";
	for (int i = 0; i < N; i++)
	{
		AllStudents[i].num = (char*)malloc(sizeof(char));//提示：num定义为指针类型，注意向其赋值内容之前要先为其申请空间。
		cin >> AllStudents[i].num >> AllStudents[i].score;
	}
	student* maxStudent1 = NULL;
	maxStudent1 = max1();
	cout << "最高分学生信息为： " << endl;
	cout << "num: " << maxStudent1->num << endl;
	cout << "score: " << maxStudent1->score << endl;

	student maxStudent2;
	maxStudent2 = max2();
	cout << "最高分学生信息为： " << endl;
	cout << "num: " << maxStudent2.num << endl;
	cout << "score: " << maxStudent2.score << endl;
	*/

	//定义一个日期结构变量，计算某日期是本年度的第几天
	/*
	date p;
	cout << "请输入查询日期的月：";
	cin >> p.mouth;
	cout << "请输入查询日期的日：";
	cin >> p.day;
	cout << p.mouth << "月" << p.day << "日" << "是2021年的第 " << date_sum(p) << " 天";
	*/

	// 删除链表中第n个结点
	/*
	int n;
	cout << "输入职工数量";
	cin >> n;
	cout << "输入职工姓名、工号、工资";
	staff* p = NULL, * x, * head = NULL, * tail = NULL;
	for (int i = 0; i < n; i++)
	{
		p = new staff;
		cin >> p->name >> p->num >> p->wage;

		if (head == NULL)
		{
			head = p;
			tail = p;
			p->next = NULL;
		}
		else
		{
			tail->next = p;
			tail = p;
			p->next = NULL;
		}
	}
	x = new staff;

	int m;
	cout << "输入要删除的职工编号";
	cin >> m;
	x = deln(head, m);

	while (x != NULL)
	{
		cout << x->name << x->num << x->wage;
		x = x->next;
		cout << endl;
	}
	*/
	//逆序存储字符串至链表
	/*
	struct abc* x;
	x = new abc;
	cout << "请输入待处理的字符串：";
	fgets(str, MAX, stdin);
	InvOrder(str);
	x = create_list();
	while (x != NULL)
	{
		cout << x->s;
		x = x->next;
	}
	*/
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
