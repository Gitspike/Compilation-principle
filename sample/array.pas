{该程序展示数组功能}
program main(input, output);
var
arr:array [1..3, 1..4, 1..5] of integer;
num:integer;
begin
	num := 2;
	arr[1][1][1] := 10;
	arr[1][1][2] := 20;
	arr[1][1][3] := arr[1][1][1] + arr[1][1][2];
	arr[2][1][3] := arr[1][1][3] * num;
	write(arr[1][1][3]);
	write(arr[2][1][3]);
end.
