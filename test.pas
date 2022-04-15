program main(input);
{测试 const 功能}
const name='l';
{测试 type 功能}
type mes=char;
{测试 var 功能}
var age:integer;

function MyFunction(x: integer; y:integer):integer;
begin
    if x > y then
         MyFunction := x
    else
         MyFunction := y
end;
{测试主函数}
begin
    {对变量赋值}
    age := MyFunction(2,1) + 1;
    writeln(age);
    { writeln(MyFunction(2,1)); }
end.