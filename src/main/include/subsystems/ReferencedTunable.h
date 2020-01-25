#pragma once

#include <memory>
#include <map>

#include <frc/smartdashboard/smartdashboard.h>

namespace frc4065
{

class ReferencedTunable
{
typedef std::pair<const char*, double*> rt_pair;
public:
    // Given pointer will be added to smartdashboard and will be updated periodically
    // from UpdateAll
    static void Register(const char* name, double& data);
    // Removes the shared_ptr registered under the provided name and removes the entry
    // on the smartdashboard.
    static void Unregister(const char* name);
    // Updates all of the registered tunables; should be called in the main roborio loop
    static void UpdateAll();
private:
    static std::map<const char*, double*> registered_tunables_;
    static unsigned char ref_count_;

    ReferencedTunable() {}
};

}