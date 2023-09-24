# Running this script will start a docker container where dependencies will be installed, SpacecraftSensorSynthesizer will be built, and the SpacecraftSensorSynthesizer Tests will be run.

sudo docker build -t s3_env .

sudo docker run -v $(pwd):/SpacecraftSensorSynthesizer s3_env