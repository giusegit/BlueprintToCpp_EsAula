// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConeActor.generated.h"

UCLASS()
class BLUEPRINTTOCPP_API AConeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConeActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ConeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
	bool bIsUp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
	float MinHeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
	float MaxHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConeActor")
	float Max;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConeActor")
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
	float CurrentZ;
	////////////////////////////////////////////////////////////////////////
	// Per la lezione sulle Funzioni
	UFUNCTION(BLueprintCallable, Category="Cone Functions")
	void TestFunc(int32 Val);

	// BlueprintPure function
	UFUNCTION(BLueprintPure, Category = "Cone Functions")
	int32 TestPureFunc();

	// se si aggiunge const alla funzione BlueprintCallable appare il Target sul nodo della funzione
	// //come se fosse Pure
	UFUNCTION(BLueprintCallable, Category = "Cone Functions")
	int32 TestPureFuncConst() const;

	// se si aggiunge il tag meta sparisce il pin self
	UFUNCTION(BLueprintCallable, Category = "Cone Functions", meta=(HideSelfPin="true"))
	int32 TestPureFuncConstHidePin() const;

	//Blueprint implementable event
	// implementata nel blueprint e chiamata nel Cpp es. nalla BeginPlay
	//non c'e' implementazione nel cpp
	UFUNCTION(BLueprintImplementableEvent, Category = "Cone Functions")
	void TestImplementableFunc(int32 Val);

	// viene visualizzata nella tab delle funzioni in Blueprint
	UFUNCTION(BLueprintImplementableEvent, Category = "Cone Functions")
	int32 TestImplementableFuncRetVal(int32 Val);

	//Blueprint native event
	UFUNCTION(BLueprintNativeEvent, Category = "Cone Functions")
	void Explode();
	void Explode_Implementation();

	UFUNCTION(BLueprintCallable, Category = "Cone Functions")
	void TestInpuitOutput(const int32 InVal, int32& OutVal1, int32& OutVal2);

	// ConeActor e' un input
	UFUNCTION(BLueprintCallable, Category = "Cone Functions")
	void TestInpuitOutput2(const int32 InVal, AConeActor* ConeActor, int32& OutVal1, int32& OutVal2);

	// ConeActor e' un output
	UFUNCTION(BLueprintCallable, Category = "Cone Functions")
	void TestInpuitOutput3(const int32 InVal, AConeActor*& ConeActor, int32& OutVal1, int32& OutVal2);

	//nel blueprint e' un input ma si puo' editare
	UFUNCTION(BLueprintCallable, Category = "Cone Functions")
	void TestInpuitOutput4(const int32 InVal, FVector Location, int32& OutVal1, int32& OutVal2);

	//nel blueprint e' un input ma non si puo' editare
	UFUNCTION(BLueprintCallable, Category = "Cone Functions")
	void TestInpuitOutput5(const int32 InVal, const FVector& Location, int32& OutVal1, int32& OutVal2);

	///////////////////////////////////////////////////////////////////////////////////////////////
	// // Per la lezione sulle UPROPERTY
	// Esempi per le UPROPERTY
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConePropertyTest")
	int32 ValVisibleAnywhere = 10;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "ConePropertyTest")
	int32 ValVisibleInstOnly = 10;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "ConePropertyTest")
	int32 ValVisibleDefaultsOnly = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConePropertyTest")
	int32 ValEditAnywhere = 10;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "ConePropertyTest")
	int32 ValEditInstanceOnly = 10;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ConePropertyTest")
	int32 ValEditDefaultsOnly = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConePropertyTest", meta=(DisplayName="Cone Speed", Tooltip="Speed tooltip", ClampMin = "10", ClampMax = "50"))
	float AnotherSpeed = 10;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

//private:
	//cosi non compila
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ConePropertyTest")
	//int32 ValPrivateWithAccess = 10;
	//cosi compila
	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ConePropertyTest", meta=(AllowPrivateAccess="true"))
	//int32 ValPrivateWithAccess = 10;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
