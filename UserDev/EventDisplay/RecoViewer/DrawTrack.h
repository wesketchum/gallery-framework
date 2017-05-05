/**
 * \file DrawTrack.h
 *
 * \ingroup RecoViewer
 *
 * \brief Class def header for a class DrawTrack
 *
 * @author cadams
 */

/** \addtogroup RecoViewer

    @{*/
#ifndef EVD_LARLITE_DRAWTRACK_H
#define EVD_LARLITE_DRAWTRACK_H

#include "Analysis/ana_base.h"
#include "lardataobj/RecoBase/Track.h"
#include <iostream>

#include "RecoBase.h"
/**
   \class DrawTrack
   User defined class DrawTrack ... these comments are used to generate
   doxygen documentation!
 */

namespace evd {

class Track2D {
public:
  friend class DrawTrack;

  const std::vector<std::pair<float, float>> &track() { return _track; }
  const std::vector<std::pair<float, float>> &direction() { return _track; }

protected:
  std::vector<std::pair<float, float>> _track;
};

// typedef std::vector<std::pair<float, float> > Track2D;

class DrawTrack : public galleryfmwk::ana_base, public RecoBase<Track2D> {

public:
  /// Default constructor
  DrawTrack();

  /// Default destructor
  ~DrawTrack();

  virtual bool initialize();

  virtual bool analyze(gallery::Event *event);

  virtual bool finalize();

private:
  Track2D getTrack2D(recob::Track track, unsigned int plane);
};

} // evd

#endif
/** @} */ // end of doxygen group
