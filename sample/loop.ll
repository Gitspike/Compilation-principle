; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
  %1 = alloca [5 x i32]
  %2 = alloca i32
  store i32 0, i32* %2
  store i32 1, i32* %2
  br label %3

3:                                                ; preds = %5, %0
  %4 = load i32, i32* %2
  %"<=" = icmp sle i32 %4, 5
  br i1 %"<=", label %5, label %13

5:                                                ; preds = %3
  %6 = load i32, i32* %2
  %7 = load i32, i32* %2
  %8 = sub i32 5, %7
  %9 = sub i32 %6, 1
  %10 = getelementptr [5 x i32], [5 x i32]* %1, i32 0, i32 %9
  store i32 %8, i32* %10
  %11 = load i32, i32* %2
  %12 = add i32 %11, 1
  store i32 %12, i32* %2
  br label %3

13:                                               ; preds = %3
  store i32 1, i32* %2
  br label %14

14:                                               ; preds = %26, %13
  %15 = load i32, i32* %2
  %"<=1" = icmp sle i32 %15, 5
  %16 = load i32, i32* %2
  %"<=2" = icmp sge i32 %16, 1
  %17 = and i1 %"<=1", %"<=2"
  br i1 %17, label %18, label %19

18:                                               ; preds = %14
  br label %20

19:                                               ; preds = %14
  ret i32 0

20:                                               ; preds = %22, %18
  %21 = load i32, i32* %2
  %"<3" = icmp slt i32 %21, 5
  br i1 %"<3", label %22, label %26

22:                                               ; preds = %20
  %23 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 9)
  %24 = load i32, i32* %2
  %25 = add i32 %24, 1
  store i32 %25, i32* %2
  br label %20

26:                                               ; preds = %20
  %27 = load i32, i32* %2
  %28 = sub i32 %27, 1
  %29 = getelementptr [5 x i32], [5 x i32]* %1, i32 0, i32 %28
  %30 = load i32, i32* %29
  %31 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %30)
  %32 = load i32, i32* %2
  %33 = add i32 %32, 1
  store i32 %33, i32* %2
  br label %14
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
