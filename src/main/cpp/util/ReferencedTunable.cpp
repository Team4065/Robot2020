#include "util/ReferencedTunable.h"

namespace frc4065
{

std::map<const char*, double*> ReferencedTunable::registered_tunables_;
unsigned char ReferencedTunable::ref_count_ = 0;

void ReferencedTunable::Register(const char* name, double& data)
{
    registered_tunables_.insert(rt_pair(name, &data));
    ref_count_++;

    frc::SmartDashboard::PutNumber(name, data);
}

void ReferencedTunable::Unregister(const char* name)
{
    if (registered_tunables_.find(name) != registered_tunables_.end())
    {
        registered_tunables_.erase(name);
        frc::SmartDashboard::Delete(name);
        ref_count_--;
    }
}

void ReferencedTunable::UpdateAll()
{
    for (const auto& [name, data] : registered_tunables_)
        *data = frc::SmartDashboard::GetNumber(name, 0.0);
}

}