#include<stdio.h>

		//�ж����꣬������0��1��ֵΪ0�������ֵ꣬Ϊ1������ 

	int is_no_leap_year(int year)
	{
		return ((year%4==0&&year%100!=0)||year%400==0);
	}
	
		//�������Ϊ29��
	
	int Day_In_Month(int year,int month)
	{
		int February_day = 28 + is_no_leap_year(year);
		int day[12] = {31,February_day,31,30,31,30,31,31,30,31,30};
		return (day[month-1]);
	}
	
int main()
{
	int startyear,nowyear,startmonth,nowmonth,startday,nowday;
	int	i,year_day_between,day_day_left,month_day_till,all_day,month_day_left,day_day_till;
	int year[150];		//year[]�Ǵ���ĵط���150��������ڵ��������ڲ��ܳ���150�� 
	int tempyear = startyear;		//tempyearΪ��ʱ���� 
	
	printf("��������Ϊ:");
	scanf("%d-%d-%d",&startyear,&startmonth,&startday);
	printf("��������Ϊ:");
	scanf("%d-%d-%d",&nowyear,&nowmonth,&nowday);
	
	if (startyear == nowyear && startmonth == nowmonth)
    {
    	all_day = nowday - startday + 1;
	}
	else
	{
		if(startyear == nowyear)
		{
			day_day_left = Day_In_Month(startyear, startmonth) - startday;
			
			for (i = 1; i < nowmonth; i++)
	    {
	        month_day_till += Day_In_Month(nowyear, i);
	    }
	
	    all_day = day_day_left + month_day_till;
		}
		else
		{	
			for(i = 0;i < nowyear-startyear-1;i++)
			{
				++tempyear;
				if(is_no_leap_year(tempyear))
				{
					year[i] = 366;
				}
				else
				{
					year[i] = 365;
				}
				year_day_between += year[i];	
			}
		
			// ������������������ʣ������
		
				day_day_left=Day_In_Month(startyear,startmonth)-startday;
				for(i = startmonth;i < 12;i++)
				{
					month_day_left += Day_In_Month(startyear, i);
				}
	
				//���㵱ǰ����ѹ�����
				
				for(i = 1;i < nowmonth;i++)
				{
					month_day_till += Day_In_Month(nowyear, i);
				}
	
				//�����ܺ� 
		
			day_day_till = nowday-1;
			all_day = year_day_between + month_day_left + month_day_till + day_day_left + day_day_till;
		}
	}
		printf("�������������:%d",all_day);
		return 0;
}

