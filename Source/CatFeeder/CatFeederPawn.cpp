// Fill out your copyright notice in the Description page of Project Settings.

#include "CatFeederPawn.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACatFeederPawn::ACatFeederPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACatFeederPawn::BeginPlay()
{
	Super::BeginPlay();

	if(Cat_Hud != nullptr)
	{
		Cat_Hud_Widget = CreateWidget(GetWorld(), Cat_Hud);
		Cat_Hud_Widget->AddToViewport();
	}
}

// Called every frame
void ACatFeederPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACatFeederPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACatFeederPawn::MovePosition(float position)
{
	FVector DesireVector(-900, position, 0);
	SetActorLocation(DesireVector);
}

