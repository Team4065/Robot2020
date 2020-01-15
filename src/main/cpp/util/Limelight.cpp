#include "util/Limelight.h"

namespace frc4065
{

Limelight::Limelight(const char* name)
: table_name_(name), table_(nt::NetworkTableInstance::GetDefault().GetTable(name))
{

}

}