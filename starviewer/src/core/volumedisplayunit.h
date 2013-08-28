#ifndef VOLUMEDISPLAYUNIT_H
#define VOLUMEDISPLAYUNIT_H

class vtkImageActor;

namespace udg {

class Image;
class ImagePipeline;
class OrthogonalPlane;
class SliceHandler;
class Volume;

/**
    This class groups together a Volume and the associated objects that a Q2DViewer needs to display a volume.
    The ImagePipeline, the vtkImageActor and the SliceHandler are created internally in the constructor and destroyed in the destructor, so only the Volume has
    to be supplied externally.
 */
class VolumeDisplayUnit {

public:
    VolumeDisplayUnit();
    ~VolumeDisplayUnit();

    /// Returns the volume.
    Volume* getVolume() const;
    /// Sets a new volume and resets display properties (pipeline and slice handler).
    void setVolume(Volume *volume);

    /// Returns the image pipeline.
    ImagePipeline* getImagePipeline() const;

    /// Returns the image actor.
    vtkImageActor* getImageActor() const;

    /// Returns the slice handler.
    SliceHandler* getSliceHandler() const;

    /// Returns the view plane.
    const OrthogonalPlane& getViewPlane() const;
    /// Sets a new view plane, resetting some properties of the slice handler.
    void setViewPlane(const OrthogonalPlane &viewPlane);

    /// Returns slice thickness of the currently displayed image.
    /// On the acquisition plane, this depends on DICOM's slice thickness and slab thickness (if DICOM's slice thickness is not defined, the method returns 0).
    /// On the other planes, this depends on the spacing and the slab thickness.
    double getSliceThickness() const;

private:
    /// The volume.
    Volume *m_volume;

    /// The image pipeline that processes the volume.
    ImagePipeline *m_imagePipeline;

    /// The image actor where the slices are rendered.
    vtkImageActor *m_imageActor;

    /// The slice handler that controls slices, phases and slabs.
    SliceHandler *m_sliceHandler;

};

}

#endif