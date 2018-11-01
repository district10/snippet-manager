def str2bool(v):
    if v.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    elif v.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    else:
        raise argparse.ArgumentTypeError('Boolean value expected. e.g. "true", "false"')

prog = 'python -m ...'
description = ('Command line interface for ...')
parser = argparse.ArgumentParser(prog=prog, description=description)
parser.add_argument('input', type=str,
                    help='input map filepath')
parser.add_argument('--ground-json', action='store', dest='ground_json',
                    help='ground json path')
parser.add_argument('--dump-geojson', action='store', dest='geojson_path',
                    help='dump geojson')
parser.add_argument('--absolute', type=str2bool, nargs='?',
                    const=True, default=False,
                    help='use absolute position in ply')
parser.add_argument('--center', action='store', dest='center',
                    help='ECEF center, comma separated, e.g. -2258830,3912409,4487419 (or lon, lat, alt center e.g. 120,45,100')
parser.add_argument('--frame-step', action='store', dest='frame_step',
                    type=int, default=Exporter.config.frame_step,
                    help='frame step for dumping')
parser.add_argument('--interactive', action='store_true', default=False,
                    help='enter into interactive mode')
parser.add_argument('--debug', action='store_true', default=False,
                    help='debug mode, print exporter config')
options = parser.parse_args()
Exporter.config.frame_step = options.frame_step
Exporter.config.export_lanes = options.export_lanes
Exporter.config.export_poles = options.export_poles
