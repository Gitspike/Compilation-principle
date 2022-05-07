program main(input, output);
var
    people: record
            name:char;
            age:integer
    end;

begin
    people.name := 'x';
    write(people.name);
end.