//
//  SineWave.cpp
//  Tonic
//
//  Created by Nick Donaldson on 2/8/13.

//

#include "SineWave.h"

namespace Tonic {
  
  SineWave::SineWave(float phase){
    
    static string const TONIC_SIN_TABLE = "_TONIC_SIN_TABLE_";
    const unsigned int tableSize = 4096;

    // As soon as the first SineWave is allocated, persistent SampleTable is created. Will stay in memory for program lifetime.
    if (!Tonic_::s_oscillatorTables()->containsObjectNamed(TONIC_SIN_TABLE)){

      SampleTable sineTable = SampleTable(tableSize+1, 1);
      TonicFloat norm = 1.0f / tableSize;
      TonicFloat *data = sineTable.dataPointer();
      for ( unsigned long i=0; i<tableSize+1; i++ ){
        *data++ = sinf( TWO_PI * i * norm );
      }
      
      Tonic_::s_oscillatorTables()->insertObject(TONIC_SIN_TABLE, sineTable);
      
      this->gen()->setLookupTable(sineTable);
    }
    else{
      this->gen()->setLookupTable(Tonic_::s_oscillatorTables()->objectNamed(TONIC_SIN_TABLE));
    }

    if (phase)
      this->gen()->setPhase((phase/(2*M_PI))*tableSize);
  }
  
} // Namespace Tonic
