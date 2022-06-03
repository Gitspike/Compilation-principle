; ModuleID = './opt.ll'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = alloca i32
  store i32 0, i32* %2
  %3 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32* %1)
  %4 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), i32* %2)
  %5 = load i32, i32* %1
  %6 = load i32, i32* %2
  br label %7

7:                                                ; preds = %8, %0
  %.01 = phi i32 [ %6, %0 ], [ %9, %8 ]
  %.0 = phi i32 [ %5, %0 ], [ %.01, %8 ]
  %"<=" = icmp ne i32 %.01, 0
  br i1 %"<=", label %8, label %10

8:                                                ; preds = %7
  %9 = srem i32 %.0, %.01
  br label %7

10:                                               ; preds = %7
  %11 = alloca i32
  store i32 %.0, i32* %11
  %12 = load i32, i32* %11
  %13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @2, i32 0, i32 0), i32 %12)
  ret i32 0
}
