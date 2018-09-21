#include "Color.h"
#include "ColorWheel.h"
#include "ColorWheelViewModel.h"
#include "Constraints.h"
#include "HueRelationshipConstraint.h"
#include "LockColorConstraint.h"
#include "MainWindow.h"
#include "SaturationRelationshipConstraint.h"
#include "Swatches.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(1280, 800);

    QSharedPointer<Swatches> swatches(new Swatches());
//    swatches->addColor(QSharedPointer<Color>::create(0.0, 1.0, 1.0));
//    swatches->addColor(QSharedPointer<Color>::create(120.0, 1.0, 1.0));
//    swatches->addColor(QSharedPointer<Color>::create(240.0, 1.0, 1.0));

//    swatches->addColor(QSharedPointer<Color>::create(60.0, 0.7, 1.0));
//    swatches->addColor(QSharedPointer<Color>::create(180.0, 0.4, 1.0));
//    swatches->addColor(QSharedPointer<Color>::create(300.0, 0.1, 1.0));

    QSharedPointer<Constraints> constraints(new Constraints());

//    {
//    QSharedPointer<LockColorConstraint> lockColorConstraint(new LockColorConstraint());
//    lockColorConstraint->setColor(swatches->colors().at(0));
//    lockColorConstraint->setIsHueLocked(false);
//    lockColorConstraint->setIsSaturationLocked(true);
//    lockColorConstraint->setIsBrightnessLocked(true);
//    constraints->addConstraint(lockColorConstraint);
//    }

//    {
//    QSharedPointer<LockColorConstraint> lockColorConstraint2(new LockColorConstraint());
//    lockColorConstraint2->setColor(swatches->colors().at(3));
//    lockColorConstraint2->setIsHueLocked(true);
//    lockColorConstraint2->setIsSaturationLocked(false);
//    lockColorConstraint2->setIsBrightnessLocked(true);
//    constraints->addConstraint(lockColorConstraint2);
//    }

//    for (int i = 1; i < 3; ++ i)
//    {
//        QSharedPointer<LockColorConstraint> lockColorConstraint2(new LockColorConstraint());
//        lockColorConstraint2->setColor(swatches->colors().at(i));
//        lockColorConstraint2->setIsHueLocked(false);
//        lockColorConstraint2->setIsSaturationLocked(true);
//        lockColorConstraint2->setIsBrightnessLocked(true);
//        constraints->addConstraint(lockColorConstraint2);
//    }

//    QSharedPointer<HueRelationshipConstraint> hueRelationshipConstraint(new HueRelationshipConstraint());
//    hueRelationshipConstraint->addColor(swatches->colors().at(0));
//    hueRelationshipConstraint->addColor(swatches->colors().at(1));
//    hueRelationshipConstraint->addColor(swatches->colors().at(2));
//    constraints->addConstraint(hueRelationshipConstraint);

//    QSharedPointer<SaturationRelationshipConstraint> saturationRelationshipConstraint(new SaturationRelationshipConstraint());
//    saturationRelationshipConstraint->addColor(swatches->colors().at(0));
//    saturationRelationshipConstraint->addColor(swatches->colors().at(1));
//    saturationRelationshipConstraint->addColor(swatches->colors().at(2));
//    constraints->addConstraint(saturationRelationshipConstraint);

//    QSharedPointer<HueRelationshipConstraint> hueRelationshipConstraint2(new HueRelationshipConstraint());
//    hueRelationshipConstraint2->addColor(swatches->colors().at(0));
//    hueRelationshipConstraint2->addColor(swatches->colors().at(3));
//    hueRelationshipConstraint2->addColor(swatches->colors().at(4));
//    constraints->addConstraint(hueRelationshipConstraint2);

//    QSharedPointer<SaturationRelationshipConstraint> saturationRelationshipConstraint2(new SaturationRelationshipConstraint());
//    saturationRelationshipConstraint2->addColor(swatches->colors().at(0));
//    saturationRelationshipConstraint2->addColor(swatches->colors().at(4));
//    saturationRelationshipConstraint2->addColor(swatches->colors().at(5));
//    constraints->addConstraint(saturationRelationshipConstraint2);

    QSharedPointer<ColorWheelViewModel> colorWheelViewModel(new ColorWheelViewModel());
    colorWheelViewModel->setSwatches(swatches);
    colorWheelViewModel->setConstraints(constraints);

    ColorWheel* colorWheel = new ColorWheel(this);
    colorWheel->setViewModel(colorWheelViewModel);

    setCentralWidget(colorWheel);
}

MainWindow::~MainWindow()
{
    delete ui;
}
