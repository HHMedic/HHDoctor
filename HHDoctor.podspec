Pod::Spec.new do |spec|
  spec.name         = 'HHDoctor'
  spec.version      = '3.1.0080614'
  spec.license      = { :type => 'MIT' }
  spec.homepage     = 'http://www.hh-medic.com'
  spec.authors      = { "HHMedic" => 'hh_client@hh-medic.com' }
  spec.summary      = 'HHMedic'
  spec.source       = { :git => 'https://github.com/HHMedic/HHDoctor.git'  }
  spec.platform     = :ios, '9.0'
  spec.vendored_frameworks = 'HHDoctor.framework'
  spec.frameworks   = 'UIKit','AVFoundation','Foundation'
  spec.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.pod_target_xcconfig = {
    'OTHER_LDFLAGS' => '-ObjC',
    'ENABLE_BITCODE' => 'NO',
  }
end
