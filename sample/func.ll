name: main  type: main   value: 
name: a  type: integer   value: 0
name: p1  type:    value: 
name: main  type: err   value: 
name: a  type: integer   value: 0
name: p1  type:    value: 
name: x  type: integer   value: 0
name: main  type: err   value: 
name: a  type: integer   value: 1
name: p1  type:    value: 
; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32* %1)
  br label %3

3:                                                ; preds = %13, %0
  %4 = load i32, i32* %1
  %"<1" = icmp slt i32 %4, 10
  br i1 %"<1", label %5, label %9

5:                                                ; preds = %3
  %6 = alloca i32
  %7 = load i32, i32* %1
  store i32 %7, i32* %6
  %8 = load i32, i32* %6
  %"<3" = icmp slt i32 %8, 5
  br i1 %"<3", label %10, label %13

9:                                                ; preds = %3
  ret i32 0

10:                                               ; preds = %5
  %11 = load i32, i32* %6
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %11)
  br label %13

13:                                               ; preds = %5, %10
  %14 = load i32, i32* %1
  %15 = add i32 %14, 1
  store i32 %15, i32* %1
  br label %3
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
