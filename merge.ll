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
  %2 = alloca [101 x i32]
  %3 = alloca i32
  store i32 0, i32* %3
  %4 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32* %1)
  br label %5

5:                                                ; preds = %7, %0
  %.0 = phi i32 [ 0, %0 ], [ %11, %7 ]
  %6 = load i32, i32* %1
  %"<" = icmp slt i32 %.0, %6
  br i1 %"<", label %7, label %12

7:                                                ; preds = %5
  %8 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), i32* %3)
  %9 = load i32, i32* %3
  %10 = getelementptr [101 x i32], [101 x i32]* %2, i32 0, i32 %.0
  store i32 %9, i32* %10
  %11 = add i32 %.0, 1
  br label %5

12:                                               ; preds = %5
  %13 = alloca i32
  store i32 0, i32* %13
  %14 = alloca i32
  store i32 0, i32* %14
  %15 = alloca i32
  store i32 0, i32* %15
  %16 = alloca i32
  store i32 0, i32* %16
  %17 = alloca i32
  store i32 0, i32* %17
  %18 = alloca i32
  store i32 0, i32* %18
  %19 = alloca [101 x i32]
  store i32 1, i32* %13
  store i32 0, i32* %15
  store i32 0, i32* %16
  store i32 0, i32* %17
  store i32 0, i32* %18
  br label %20

20:                                               ; preds = %42, %12
  %21 = load i32, i32* %13
  %22 = load i32, i32* %1
  %"<1" = icmp slt i32 %21, %22
  br i1 %"<1", label %23, label %24

23:                                               ; preds = %20
  store i32 0, i32* %15
  br label %25

24:                                               ; preds = %20
  br label %112

25:                                               ; preds = %110, %23
  %26 = load i32, i32* %15
  %27 = load i32, i32* %1
  %28 = load i32, i32* %13
  %29 = sub i32 %27, %28
  %"<2" = icmp slt i32 %26, %29
  br i1 %"<2", label %30, label %42

30:                                               ; preds = %25
  %31 = load i32, i32* %15
  %32 = load i32, i32* %13
  %33 = add i32 %31, %32
  store i32 %33, i32* %16
  %34 = load i32, i32* %15
  %35 = load i32, i32* %13
  %36 = add i32 %34, %35
  store i32 %36, i32* %17
  %37 = load i32, i32* %17
  %38 = load i32, i32* %13
  %39 = add i32 %37, %38
  store i32 %39, i32* %18
  %40 = load i32, i32* %18
  %41 = load i32, i32* %1
  %"<3" = icmp sgt i32 %40, %41
  %"<4" = icmp sgt i32 %40, %41
  br i1 %"<4", label %45, label %47

42:                                               ; preds = %25
  %43 = load i32, i32* %13
  %44 = shl i32 %43, 1
  store i32 %44, i32* %13
  br label %20

45:                                               ; preds = %30
  %46 = load i32, i32* %1
  store i32 %46, i32* %18
  br label %48

47:                                               ; preds = %30
  br label %48

48:                                               ; preds = %47, %45
  store i32 0, i32* %14
  br label %49

49:                                               ; preds = %83, %48
  %50 = load i32, i32* %15
  %51 = load i32, i32* %16
  %"<5" = icmp slt i32 %50, %51
  %"<6" = icmp slt i32 %50, %51
  %52 = load i32, i32* %17
  %53 = load i32, i32* %18
  %"<7" = icmp slt i32 %52, %53
  %54 = and i1 %"<6", %"<7"
  br i1 %54, label %55, label %62

55:                                               ; preds = %49
  %56 = load i32, i32* %15
  %57 = getelementptr [101 x i32], [101 x i32]* %2, i32 0, i32 %56
  %58 = load i32, i32* %57
  %59 = load i32, i32* %17
  %60 = getelementptr [101 x i32], [101 x i32]* %2, i32 0, i32 %59
  %61 = load i32, i32* %60
  %"<8" = icmp slt i32 %58, %61
  br i1 %"<8", label %63, label %73

62:                                               ; preds = %49
  br label %84

63:                                               ; preds = %55
  %64 = load i32, i32* %14
  %65 = load i32, i32* %15
  %66 = getelementptr [101 x i32], [101 x i32]* %2, i32 0, i32 %65
  %67 = load i32, i32* %66
  %68 = getelementptr [101 x i32], [101 x i32]* %19, i32 0, i32 %64
  store i32 %67, i32* %68
  %69 = load i32, i32* %14
  %70 = add i32 %69, 1
  store i32 %70, i32* %14
  %71 = load i32, i32* %15
  %72 = add i32 %71, 1
  store i32 %72, i32* %15
  br label %83

73:                                               ; preds = %55
  %74 = load i32, i32* %14
  %75 = load i32, i32* %17
  %76 = getelementptr [101 x i32], [101 x i32]* %2, i32 0, i32 %75
  %77 = load i32, i32* %76
  %78 = getelementptr [101 x i32], [101 x i32]* %19, i32 0, i32 %74
  store i32 %77, i32* %78
  %79 = load i32, i32* %14
  %80 = add i32 %79, 1
  store i32 %80, i32* %14
  %81 = load i32, i32* %17
  %82 = add i32 %81, 1
  store i32 %82, i32* %17
  br label %83

83:                                               ; preds = %73, %63
  br label %49

84:                                               ; preds = %87, %62
  %85 = load i32, i32* %15
  %86 = load i32, i32* %16
  %"<9" = icmp slt i32 %85, %86
  br i1 %"<9", label %87, label %97

87:                                               ; preds = %84
  %88 = load i32, i32* %14
  %89 = load i32, i32* %15
  %90 = getelementptr [101 x i32], [101 x i32]* %2, i32 0, i32 %89
  %91 = load i32, i32* %90
  %92 = getelementptr [101 x i32], [101 x i32]* %19, i32 0, i32 %88
  store i32 %91, i32* %92
  %93 = load i32, i32* %14
  %94 = add i32 %93, 1
  store i32 %94, i32* %14
  %95 = load i32, i32* %15
  %96 = add i32 %95, 1
  store i32 %96, i32* %15
  br label %84

97:                                               ; preds = %84
  br label %98

98:                                               ; preds = %100, %97
  %99 = load i32, i32* %14
  %"<10" = icmp sgt i32 %99, 0
  %"<11" = icmp sgt i32 %99, 0
  br i1 %"<11", label %100, label %110

100:                                              ; preds = %98
  %101 = load i32, i32* %17
  %102 = sub i32 %101, 1
  store i32 %102, i32* %17
  %103 = load i32, i32* %14
  %104 = sub i32 %103, 1
  store i32 %104, i32* %14
  %105 = load i32, i32* %17
  %106 = load i32, i32* %14
  %107 = getelementptr [101 x i32], [101 x i32]* %19, i32 0, i32 %106
  %108 = load i32, i32* %107
  %109 = getelementptr [101 x i32], [101 x i32]* %2, i32 0, i32 %105
  store i32 %108, i32* %109
  br label %98

110:                                              ; preds = %98
  %111 = load i32, i32* %18
  store i32 %111, i32* %15
  br label %25

112:                                              ; preds = %114, %24
  %.1 = phi i32 [ 0, %24 ], [ %118, %114 ]
  %113 = load i32, i32* %1
  %"<12" = icmp slt i32 %.1, %113
  br i1 %"<12", label %114, label %119

114:                                              ; preds = %112
  %115 = getelementptr [101 x i32], [101 x i32]* %2, i32 0, i32 %.1
  %116 = load i32, i32* %115
  %117 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @2, i32 0, i32 0), i32 %116)
  %118 = add i32 %.1, 1
  br label %112

119:                                              ; preds = %112
  ret i32 0
}
