/**
 * \file DrawShower.h
 *
 * \ingroup RecoViewer
 *
 * \brief Class def header for a class DrawShower
 *
 * @author cadams
 */

/** \addtogroup RecoViewer

    @{*/
#ifndef EVD_DRAWSHOWER_H
#define EVD_DRAWSHOWER_H

#include <iostream>
#include "Analysis/anabase.h"

#include "RecoBase.h"
#include "DrawCluster.h"

#include "lardataobj/RecoBase/Shower.h"
/**
   \class DrawShower
   User defined class DrawShower ... these comments are used to generate
   doxygen documentation!
 */


namespace evd {

class Shower2D  {

public:

    /// Default constructor
    Shower2D() {}

    /// Default destructor
    ~Shower2D() {}

    int plane() {return _plane;}
    larutil::Point2D startPoint() {return _startPoint;}
    larutil::Point2D endPoint() {return _endPoint;}
    float angleInPlane() {return _angleInPlane;}
    float openingAngle() {return _openingAngle;}
    float length() {return _length;}
    bool is_good() {return _is_good;}
    float dedx() {return _dedx;}
    float energy() { return _energy; }

    // ALL OF THESE VARIABLES ARE THE PROJECTION INTO THE PLANE
    int _plane;                ///< The Plane of the shower
    larutil::Point2D _startPoint;      ///< Wire time start point (units in cm)
    larutil::Point2D _endPoint;      ///< Wire time start point (units in cm)
    float _angleInPlane;       ///< Angle in the plane
    float _openingAngle;       ///< Opening angle
    float _length;             ///< Length in cm
    float _energy;             ///< Energy in MeV
    bool _is_good;             ///< Whether or not the projection succeeded
    float _dedx;                ///< dedx in collection plane, for printout

    // cluster collection
    std::vector<evd::Cluster2D> _showerCluster_v;

};


class DrawShower : public galleryfmwk::anabase, public RecoBase<Shower2D> {

public:

    /// Default constructor
    DrawShower();

    /// Default destructor
    // ~DrawShower(){}

    /** IMPLEMENT in DrawCluster.cc!
        Initialization method to be called before the analysis event loop.
    */
    virtual bool initialize();

    /** IMPLEMENT in DrawCluster.cc!
        Analyze a data event-by-event
    */
    virtual bool analyze(gallery::Event * event);

    /** IMPLEMENT in DrawCluster.cc!
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();


    // void setProducer(std::string s){producer = s;}


    // const std::vector< ::evd::Shower2D >   & getShowersByPlane(unsigned int p) const;
    // const shower2D getShower(unsigned int plane, unsigned int index) const;

    // Showers get drawn as cones.  Need a start point, and start direction
    // Also need an opening angle and the length
    // Return these as shower2D objects
    // This shows how to handle abstract objects in the viewer



    Shower2D getShower2d(recob::Shower shower, unsigned int plane);

};

} // evd

#endif
/** @} */ // end of doxygen group

