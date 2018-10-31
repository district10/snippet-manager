function PushQue {
    Que=(${Que[@]} $1)
    gpu_Que=(${gpu_Que[@]} $2)
    Nrun=$(($Nrun+1))
}
function GenQue {
    OldQue=(${Que[@]})
    Old_gpu_Que=(${gpu_Que[@]})
    Que=(); gpu_Que=(); Nrun=0
    for (( i=0; i<${#OldQue[@]}; i++ ))
    do
        PID=${OldQue[$i]}
        if [[ -d /proc/$PID ]]; then
            PushQue $PID ${Old_gpu_Que[$i]}
        fi
    done
    Nrun=${#Que[@]hQue $PID $gpu_no
}
}
function ChkQue {
    OldQue=(${Que[@]})
    for PID in ${OldQue[@]}
        do
        if [[ ! -d /proc/$PID ]]; then
            GenQue; break
        fi
    done
}

Nproc=6
Nrun=0
gpu_no=0

for packet in `cat list.txt`
do
    echo $packet
    bash master.sh $packet &
    PID=$!
    PushQue $PID $gpu_no
    while [[ $Nrun -ge $Nproc ]]
    do
    ChkQue
    sleep 1
    done

    for (( i=0; i<$Nproc; i++ ))
    do
    if [[ ${gpu_Que[@]} =~ $i ]]; then
            continue
    else
        gpu_no=$i
        break
    fi
    done
done
wait
