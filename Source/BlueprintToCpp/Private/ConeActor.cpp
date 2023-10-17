// Fill out your copyright notice in the Description page of Project Settings.


#include "ConeActor.h"

// Sets default values
AConeActor::AConeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	ConeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	Scene->SetupAttachment(GetRootComponent());
	ConeMesh->SetupAttachment(Scene);

	Speed = 50.f;
	Max = 200.f;

}

void AConeActor::TestFunc(int32 Val)
{
	//si aggiunge un LOG in output
	UE_LOG(LogTemp, Warning, TEXT("Test Func Called with value %d"), Val);
}

int32 AConeActor::TestPureFunc()
{
	return 25;
}

int32 AConeActor::TestPureFuncConst() const
{
	return 72;
}

int32 AConeActor::TestPureFuncConstHidePin() const
{
	return 77;
}

void AConeActor::Explode_Implementation()
{
	this->Destroy();
}

void AConeActor::TestInpuitOutput(const int32 InVal, int32& OutVal1, int32& OutVal2)
{
	OutVal1 = InVal;
	OutVal2 = InVal;
}

void AConeActor::TestInpuitOutput2(const int32 InVal, AConeActor* ConeActor, int32& OutVal1, int32& OutVal2)
{
	OutVal1 = InVal;
	OutVal2 = InVal;
}

void AConeActor::TestInpuitOutput3(const int32 InVal, AConeActor*& ConeActor, int32& OutVal1, int32& OutVal2)
{
	OutVal1 = InVal;
	OutVal2 = InVal;
}

void AConeActor::TestInpuitOutput4(const int32 InVal, FVector Location, int32& OutVal1, int32& OutVal2)
{
	OutVal1 = InVal;
	OutVal2 = InVal;
}

void AConeActor::TestInpuitOutput5(const int32 InVal, const FVector& Location, int32& OutVal1, int32& OutVal2)
{
	// Location.X = 3;  // non si puo' scrivere..errore
	OutVal1 = InVal;
	OutVal2 = InVal;
}

// Called when the game starts or when spawned
void AConeActor::BeginPlay()
{
	Super::BeginPlay();

	// per la lezione sulle funzioni
	// Aggiunta per la BlueprintImplementableFunction
	// TestImplementableFunc(76);
	// BlueprintImplementableFunction con valore di ritorno
	// int32 RetVal = TestImplementableFuncRetVal(99);
	// TestImplementableFunc(RetVal);
	const FVector Location = GetActorLocation();
	CurrentZ = Location.Z;
	MinHeight = Location.Z;
	MaxHeight = Location.Z + Max;
	bIsUp = true;
	
}

// Called every frame
void AConeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float Val = DeltaTime * Speed;

	if (bIsUp)
	{
		CurrentZ = CurrentZ + Val;
	}
	else
	{
		CurrentZ = CurrentZ - Val;
	}

	FVector Location = GetActorLocation();
	Location.Z = CurrentZ;

	SetActorLocation(Location);

	if (CurrentZ > MaxHeight)
	{
		bIsUp = false;
		// Per la lezione sulle funzioni
		// aggiunta per provare la funzione BlueprintNativeEvent
		// Explode();
	}
	else if (CurrentZ < MinHeight)
	{
		bIsUp = true;
	}
}

