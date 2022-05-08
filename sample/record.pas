{该程序演示结构体相关的功能}
program main(input, output);
var
	people: record
		name:char;
		age:integer
	end;

begin
	people.name := 'x';
	people.age := 18;
	write(people.name);
	write(people.age);
	people.age := people.age + 1;
	write(people.age);
end.
