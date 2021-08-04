Pod::Spec.new do |spec|
  spec.name         = 'HHDoctor'
  spec.version      = '1.0.080315'
  spec.license      = { :type => 'MIT' }
  spec.homepage     = 'https://github.com/HHMedic/HHDoctor.git'
  spec.authors      = { "HHMedic" => 'hh_client@hh-medic.com' }
  spec.summary      = 'HHMedic'
  spec.source       = { :git => 'https://github.com/HHMedic/HHDoctor.git'  }
  spec.platform     = :ios, '9.0'
  spec.vendored_frameworks = 'HHDoctor.framework'
  spec.frameworks   = 'UIKit','AVFoundation','Foundation'
  spec.pod_target_xcconfig = {
    'OTHER_LDFLAGS' => '-ObjC',
    'ENABLE_BITCODE' => 'NO',
    'ARCHS' => ['arm64', 'x86_64']
  }
end
