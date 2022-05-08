{该程序演示复杂的计算功能}
program main(input, output);
const
rate=0.5;
var
int1,int2:integer;
float:real;
begin
	int1 := 10;
	int2 := 5;
	int1 := (int1 + int2) * int1;	{(10 + 5) * 10 = 150}
	write(int1);
	float := 0.1;
	float := int1 * float;
	write(float);
	write(int2 * rate);
end.
	
