<template>
    <div style="padding: 1.25rem">
        <h6 class="text-uppercase text-secondary font-weight-bolder pt-4"> Review List</h6>
        <div class="border-bottomvd-more d-md-block" v-for="number in 3" :key="number">
            <div class="row pt-4">
                <div class="col-md-6">
                    tom smith
                </div>
                <div class="col-md-6 d-flex justify-content-end">
                    star rating
                </div>
            </div>
            <div class="row">
                <div class="col-md-12">
                    Adding 5minutes ago
                </div>
            </div>
            <div class="row pt-4">
                <div class="col-md-12">
                    Content of the review
                </div>
            </div>
        </div>
    </div>
</template>

