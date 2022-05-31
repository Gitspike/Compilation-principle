; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
  %1 = alloca [60 x i32]
  %2 = alloca [4 x i8]
  %3 = alloca i32
  store i32 0, i32* %3
  %4 = alloca i32
  store i32 0, i32* %4
  %5 = alloca i32
  store i32 0, i32* %5
  %6 = getelementptr [60 x i32], [60 x i32]* %1, i32 0, i32 13
  store i32 3, i32* %6
  %7 = getelementptr [60 x i32], [60 x i32]* %1, i32 0, i32 13
  %8 = load i32, i32* %7
  %9 = getelementptr [60 x i32], [60 x i32]* %1, i32 0, i32 7
  store i32 %8, i32* %9
  %10 = getelementptr [60 x i32], [60 x i32]* %1, i32 0, i32 7
  %11 = load i32, i32* %10
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %11)
  %13 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), i32* %4)
  %14 = load i32, i32* %4
  store i32 %14, i32* %5
  %15 = load i32, i32* %5
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @2, i32 0, i32 0), i32 %15)
  ret i32 0
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
