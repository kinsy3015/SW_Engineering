import os
import sys

################################################################################################
################################################################################################


space = ' '
enter = ' \ \n'

# paths

#os.system("docker login nvcr.io")

tao_ngc_path = '/root/'

tao_eval_trained_model_path = ''

tao_eval_eval_config_path = ''

tao_prune_model_path = ''

tao_prune_output_model_path = ''

tao_prune_retrain_eval_path = ''

tao_prune_ratrain_output_path = ''

tao_key_path = ''

tao_dest_path = ''

tao_eval_tlt_model_path = ''

tao_retrain_path = ''

#check available model resistry
#os.system( tao_ngc_path + 'ngc registry model list nvidia/tao/pretrained_detectnet_v2:*')

# clis

tao_default = 'tao'

tao_model_name = 'detectnet_v2'

tao_regist_cli = 'registry'

tao_model_cli = 'model'

tao_visualize_cli = 'inference'

tao_dataset_convert_cli = 'dataset_convert'

tao_eval_cli = 'evaluate'

tao_export_cli = 'export'

tao_info_cli = 'info'

tao_prune_cli = "prune"

# flags


tao_key_flag = '-k'

tao_eval_trained_flag = '-e'

tao_dest_falg = '--dest'

tao_gpu_flags = "nvidia_tao --gpus"

tao_data_format_flag = '-f'

tao_image_flag = '-i'

tao_output_model_flag = '-o'

tao_model_flag = '-m'

tao_batch_flag = '-m'

tao_threshold_flag = '-pth'

tao_equal_flag = '-eq'

tao_newly_model_flag = '-n'

tao_retrain_flag = '-r'

# export flags

tao_export_data_type_flag = '--data_type'

tao_export_batch_size_flag = '--batch_size'

tao_export_max_batch_size_flag = '--max_batch_size'

tao_export_engin_file_flag = '--engine_file'

tao_export_cal_cache_file_flag = '--cal_cache_file'

tao_export_verbose_flag = '--verbose'



# value

tao_gpu_num = str(8)

tao_equal_union = 'union'

tao_batch_num = '10'

tao_threshold_value = '0.0000052'



# export flags

tao_export_data_type_value = '--data_type'

tao_export_batch_size_value = '--batch_size'

tao_export_max_batch_size_value = '--max_batch_size'

tao_export_engin_file_value = '--engine_file'

tao_export_cal_cache_file_value = '--cal_cache_file'



################################################################################################
################################################################################################
# custom cli



tao_train_string = tao_ngc_path + tao_default + tao_model_name + tao_gpu_flags + tao_gpu_num
print(tao_train_string)

tao_test_string = tao_ngc_path

tao_eval_string = tao_ngc_path




#os.system(tao_string)


################################################################################################
################################################################################################
# example cli


# tao info
#os.system(tao_default + enter + tao_info_cli)

# tao training
os.system(tao_default + space + tao_model_name + space + tao_eval_trained_flag + space + tao_eval_trained_model_path
          + enter + tao_model_flag + space + tao_eval_eval_config_path + enter + tao_key_flag + space
          + tao_key_path
          )

# tao evaluate
os.system(tao_default + tao_model_name + tao_eval_cli + tao_eval_trained_flag + tao_eval_trained_flag + tao_model_flag + tao_eval_trained_model_path
          + tao_key_flag + tao_key_path
          )


# tao prune
os.system(tao_default + tao_model_name + tao_prune_cli + tao_model_flag + tao_prune_model_path + tao_output_model_flag + tao_prune_output_model_path
          + tao_equal_flag + tao_equal_union + tao_threshold_flag + tao_threshold_value + tao_key_flag + tao_key_path
          )


# tao retrain prune model
os.system( tao_default + tao_model_name + tao_eval_trained_flag + tao_prune_retrain_eval_path + tao_retrain_flag + tao_prune_ratrain_output_path
           + tao_key_flag + tao_key_path
           )