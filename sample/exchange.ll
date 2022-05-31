name: main  type: main   value: 
name: a  type: integer   value: 0
name: b  type: integer   value: 0
name: exchangeIfGt  type: integer   value: 
name: main  type: err   value: 
name: a  type: integer   value: 0
name: b  type: integer   value: 0
name: exchangeIfGt  type: integer   value: 
name: z  type: integer   value: 0
name: main  type: err   value: 
name: a  type: integer   value: 0
name: b  type: integer   value: 0
name: exchangeIfGt  type: integer   value: 
; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@2 = private unnamed_addr constant [6 x i8] c"%c%d\0A\00", align 1
@3 = private unnamed_addr constant [6 x i8] c"%c%d\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = alloca i32
  store i32 0, i32* %2
  %3 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32* %1)
  %4 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), i32* %2)
  %5 = alloca i32
  store i32 0, i32* %5
  %6 = load i32, i32* %1
  %7 = load i32, i32* %2
  %"<" = icmp sgt i32 %6, %7
  br i1 %"<", label %8, label %12

8:                                                ; preds = %0
  %9 = load i32, i32* %1
  store i32 %9, i32* %5
  %10 = load i32, i32* %2
  store i32 %10, i32* %1
  %11 = load i32, i32* %5
  store i32 %11, i32* %2
  br label %12

12:                                               ; preds = %0, %8
  %13 = load i32, i32* %1
  %14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @2, i32 0, i32 0), i8 97, i32 %13)
  %15 = load i32, i32* %2
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @3, i32 0, i32 0), i8 98, i32 %15)
  ret i32 0
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
