; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [5 x i8] c"%lf\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@3 = private unnamed_addr constant [5 x i8] c"%lf\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = alloca i32
  store i32 0, i32* %2
  %3 = alloca i32
  store i32 0, i32* %3
  %4 = alloca double
  store double 0.000000e+00, double* %4
  %5 = alloca [60 x i32]
  %6 = bitcast [60 x i32]* %5 to i32*
  store i32 2, i32* %6
  %7 = getelementptr [60 x i32], [60 x i32]* %5, i32 0, i32 1
  store i32 1, i32* %7
  %8 = getelementptr [60 x i32], [60 x i32]* %5, i32 0, i32 1
  %9 = load i32, i32* %8
  %10 = add i32 %9, 4
  store i32 %10, i32* %1
  %11 = load i32, i32* %1
  %12 = sitofp i32 %11 to double
  %13 = fmul double %12, 2.500000e+00
  store double %13, double* %4
  %14 = load double, double* %4
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @0, i32 0, i32 0), double %14)
  %16 = load double, double* %4
  %">1" = fcmp ogt double %16, 5.000000e+00
  br i1 %">1", label %17, label %28

17:                                               ; preds = %0
  %18 = alloca i32
  %19 = load i32, i32* %1
  store i32 %19, i32* %18
  %20 = alloca i32
  %21 = load i32, i32* %2
  store i32 %21, i32* %20
  %22 = alloca i32
  store i32 0, i32* %22
  %23 = load i32, i32* %18
  %24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %23)
  %25 = load i32, i32* %18
  %26 = sub i32 %25, 1
  store i32 %26, i32* %18
  %27 = alloca i32
  store i32 8, i32* %27
  br label %31

28:                                               ; preds = %0
  %29 = load i32, i32* %2
  %30 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @2, i32 0, i32 0), i32 %29)
  br label %31

31:                                               ; preds = %28, %17
  %32 = load i32, i32* %1
  %33 = sitofp i32 %32 to double
  %34 = fmul double %33, 0x3FF3333340000000
  %35 = fadd double 3.000000e+00, %34
  %36 = fsub double %35, 1.500000e+00
  store double %36, double* %4
  %37 = load double, double* %4
  %38 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @3, i32 0, i32 0), double %37)
  ret i32 0
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }