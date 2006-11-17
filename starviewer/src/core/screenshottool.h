/***************************************************************************
 *   Copyright (C) 2005-2006 by Grup de Gr�fics de Girona                  *
 *   http://iiia.udg.es/GGG/index.html?langu=uk                            *
 *                                                                         *
 *   Universitat de Girona                                                 *
 ***************************************************************************/
#ifndef UDGSCREENSHOTTOOL_H
#define UDGSCREENSHOTTOOL_H

#include "tool.h"

class vtkWindowToImageFilter;
class vtkRenderWindow;

namespace udg {

/**
Fa captures dels visors

	@author Grup de Gr�fics de Girona  ( GGG ) <vismed@ima.udg.es>
*/

class Q2DViewer;

class ScreenShotTool: public Tool
{
Q_OBJECT
public:
    ScreenShotTool(Q2DViewer *viewer , QObject *parent = 0, const char *name = 0 );

    ~ScreenShotTool();

    void handleEvent( unsigned long eventID );

private slots:
    /// Captura la imatge actual
    void screenShot();

private:
    /// El filtre per obtenir la imatge
    vtkWindowToImageFilter *m_windowToImageFilter;

    ///El render window, necessari per al filtre per desar la imatge
    vtkRenderWindow *m_renderWindow;
};

}

#endif
