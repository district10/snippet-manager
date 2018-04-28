order.getOrderStatuses().stream()
        .filter(orderStatusHistory -> orderStatusHistory.getStatus() == PRE_INSPECTION_DONE)
        .filter(orderStatusHistory -> orderStatusHistory.getStatus() == WIP_CREATED)
        .findFirst()
        .ifPresent(orderStatusHistory ->
                preInspectionTimeDto.setPreInspectionEndTime(orderStatusHistory.getOccurredTime()));
