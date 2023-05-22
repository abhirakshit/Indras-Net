// Fill out your copyright notice in the Description page of Project Settings.


#include "ThoughtCoordinateFunctions.h"
#include "Math/Vector.h"
#include "Math/UnrealMathUtility.h"


FVector UThoughtCoordinateFunctions::CalculateIntersectionPoint(const FVector& SphereCenter, float SphereRadius, const FVector& PointInsideSphere, const FVector& DirectionVector, bool& bSuccessful)
{
    FVector Direction = DirectionVector.GetSafeNormal();
    float A = FVector::DotProduct(Direction, Direction);
    float B = 2 * FVector::DotProduct(Direction, PointInsideSphere - SphereCenter);
    float C = (PointInsideSphere - SphereCenter).SizeSquared() - FMath::Square(SphereRadius);

    float Discriminant = FMath::Square(B) - 4 * A * C;

    if (Discriminant < 0)
    {
        bSuccessful = false;
        return FVector::ZeroVector;
    }

    float T1 = (-B + FMath::Sqrt(Discriminant)) / (2 * A);
    float T2 = (-B - FMath::Sqrt(Discriminant)) / (2 * A);

    float T = FMath::Max(T1, T2);

    FVector Intersection = PointInsideSphere + T * Direction;

    bSuccessful = true;
    return Intersection;
}

FVector UThoughtCoordinateFunctions::CalculateReflection(const FVector& SphereCenter, float SphereRadius, const FVector& PointInsideSphere, const FVector& DirectionVector, float ReflectionCoefficient, bool& bSuccessful, FVector& ReflectedDirection)
{
    FVector Direction = DirectionVector.GetSafeNormal();
    float A = FVector::DotProduct(Direction, Direction);
    float B = 2 * FVector::DotProduct(Direction, PointInsideSphere - SphereCenter);
    float C = (PointInsideSphere - SphereCenter).SizeSquared() - FMath::Square(SphereRadius);

    float Discriminant = FMath::Square(B) - 4 * A * C;

    if (Discriminant < 0)
    {
        bSuccessful = false;
        return FVector::ZeroVector;
    }

    float T1 = (-B + FMath::Sqrt(Discriminant)) / (2 * A);
    float T2 = (-B - FMath::Sqrt(Discriminant)) / (2 * A);

    float T = FMath::Max(T1, T2);

    FVector Intersection = PointInsideSphere + T * Direction;

    // Compute the normal at the intersection point (from the sphere's center to the intersection)
    FVector Normal = (Intersection - SphereCenter).GetSafeNormal();

    // Compute the reflected direction
    ReflectedDirection = Direction - 2 * (FVector::DotProduct(Direction, Normal)) * Normal;

    // Multiply the reflected direction by the reflection coefficient
    ReflectedDirection *= ReflectionCoefficient;

    bSuccessful = true;
    return ReflectedDirection;
}

