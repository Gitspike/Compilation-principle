{该程序演示流程控制if、函数参数的引用调用以及输入输出功能}
program main(input);
var
	a,b:integer;
function exchangeIfGt(var x:integer; var y:integer):integer;
	{如果参数 x > y，那么就会交换这两个参数的值}
	var
		z:integer;
	begin
		if x>y then
		begin
			z:=x;
			x:=y;
			y:=z;
		end;
	end;
begin
	{从标准输入中读取待交换的两个值}
	read(a);
	read(b);
	exchangeIfGt(a,b);	
	write('a', a);
	write('b', b);
end.
	
	
